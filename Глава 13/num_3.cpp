#include <iostream>
#include <cassert>
     
class IntArray
{
private:
    int m_length{ 0 };
    int *m_array{ nullptr };
public:
    IntArray(int length)
    {
        m_length = length;
        assert(length > 0 && "IntArray length should be a positive int");
        m_array = new int[m_length]{};
    } 
    IntArray(const IntArray &array)  
    {
        m_length = array.m_length;
        m_array = new int[m_length];
        for (int count{ 0 }; count < array.m_length; ++count)
        m_array[count] = array.m_array[count];
    }
    int& operator[] (const int index)
    {
        assert(index >= 0);
        assert(index < m_length);
        return m_array[index];
    }
    friend std::ostream& operator<<(std::ostream &out, const IntArray &array)
    {
        for (int count{ 0 }; count < array.m_length; ++count)
        {
            out << array.m_array[count] << ' ';
        }
        return out;       
    }
    IntArray& operator= (const IntArray &array)
    {
        if (this == &array)
        {
            return *this;
        }
        delete[] m_array;
        m_length = array.m_length;
        m_array = new int[m_length];
        for (int count{ 0 }; count < array.m_length; ++count)
        {
            m_array[count] = array.m_array[count];
        }
        return *this;
    } 
    ~IntArray()
    {
        delete[] m_array;
    }
};
     
IntArray fillArray()
{
    IntArray a(5);
    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;
    return a;
}
     
int main()
{
    IntArray a{ fillArray() };
     
    // Если вы получаете здесь непонятные значения, вы, вероятно, забыли
    // выполнить глубокое копирование в своем конструкторе копирования
    std::cout << a << '\n';
 
    auto &ref{ a }; // используем эту ссылку, чтобы избежать
                    // ошибок компиляции, связанных с самоприсваиванием
    a = ref;
 
    IntArray b(1);
    b = a;
 
    // Если вы получаете здесь непонятные значения, вы, вероятно, забыли
    // выполнить глубокое копирование в своем операторе присваивания
    std::cout << b << '\n';
 
    return 0;
}