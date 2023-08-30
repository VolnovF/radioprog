#include <iostream>
#include <cstdint>
     
class Average
{
private:
    std::int_least32_t m_sum{ 0 }; 
    std::int_least8_t m_count{ 0 };
public:
    friend std::ostream& operator<<(std::ostream &out, const Average &average)
    {
        out << static_cast<double>(average.m_sum) / average.m_count;
        return out;
    }
    Average& operator+=(int number)
    {
        m_sum += number;
        ++m_count;
        return *this;
    }
};
     
int main()
{
    Average avg{};

    avg += 4;
    std::cout << avg << '\n';
    
    avg += 8;
    std::cout << avg << '\n';

    avg += 24;
    std::cout << avg << '\n';
 
    avg += -10;
    std::cout << avg << '\n';
     
    (avg += 6) += 10; // два вызова объединены в цепочку
    std::cout << avg << '\n';
     
    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}