#include <iostream>
#include <cmath>

class FixedPoint2
{
private:
    std::int_least16_t m_beforePoint{};
    std::int_least8_t m_afterPoint{};
public:
    FixedPoint2(std::int_least16_t beforePoint = 0, std::int_least8_t afterPoint = 0): 
        m_beforePoint{ beforePoint }, m_afterPoint{ afterPoint }
    {
        if (m_beforePoint < 0 || m_afterPoint < 0)
        {
            if (m_beforePoint > 0)
            {
                m_beforePoint = -m_beforePoint;
            }
            if (m_afterPoint > 0)
            {
                m_afterPoint = -m_afterPoint;
            }
        }
    }
    FixedPoint2(double d):
        m_beforePoint{ static_cast<std::int_least16_t>(std::round(d * 100) / 100) },
        m_afterPoint{ static_cast<std::int_least8_t>(std::round(d * 100) - m_beforePoint * 100) }
    {
    }

    operator double() const
    {
        return (m_beforePoint + (static_cast<double>(m_afterPoint) / 100.0));
    }
    friend bool operator==(const FixedPoint2 &fraction1, const FixedPoint2 &fraction2)
    {
        return (fraction1.m_beforePoint == fraction2.m_beforePoint && fraction1.m_afterPoint == fraction2.m_afterPoint);
    }
    FixedPoint2 operator-() const
    {
        return {
            static_cast<std::int_least16_t>(-m_beforePoint),
            static_cast<std::int_least8_t>(-m_afterPoint)
        };
    }
};

FixedPoint2 operator+(const FixedPoint2 &fraction1, const FixedPoint2 &fraction2)
{
    return { static_cast<double>(fraction1) + static_cast<double>(fraction2) };
}
std::ostream& operator<<(std::ostream &out, const FixedPoint2 &fraction)
{
    out << static_cast<double>(fraction);
    return out;
}
std::istream& operator>> (std::istream &in, FixedPoint2 &fraction)
{
    double d{};
    in >> d;
    fraction = FixedPoint2{ d };
    return in;
}



void testAddition()
{
    std::cout << std::boolalpha;
    // оба положительные, без переполнения дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n';
    // оба положительные, с переполнением дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n';
    // оба отрицательные, без переполнения дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n';
    // оба отрицательные, с переполнением дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n';
    // второе отрицательное, без переполнения дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n';
    // второе отрицательное, возможно переполнение дробной части
    std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n';
   // первое отрицательное, без переполнения дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n';
    // первое отрицательное, возможно переполнение дробной части
    std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n';
}
 
int main()
{
    testAddition();
 
    FixedPoint2 a{ -0.48 };
    std::cout << a << '\n';
 
    std::cout << -a << '\n';
 
    std::cout << "Enter a number: "; // введите 5.678
    std::cin >> a;
    
    std::cout << "You entered: " << a << '\n';
 
    return 0;
}