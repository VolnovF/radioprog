#include <iostream>
#include <algorithm>
#include <vector>
 
class Point
{
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:
    Point(int x, int y, int z): 
        m_x{ x },
        m_y{ y },
        m_z{ z }
    {
    }
    friend std::ostream& operator<<(std::ostream& out, const Point& point)
    {
        return out << "Point(" 
            << point.m_x << ", "
            << point.m_y << ", "
            << point.m_z << ')';
    }
};
 
class Shape
{
public:
    virtual std::ostream& print( std::ostream& out ) const = 0;
    friend std::ostream& operator<<( std::ostream& out, const Shape&  figure )
    {
        return  figure.print(out);
    }
    virtual ~Shape() = default;
};
 
class Triangle : public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3):
        m_p1{ p1 },
        m_p2{ p2 },
        m_p3{ p3 }
    {
    }
    std::ostream& print(std::ostream& out) const override
    {
        return out << "Triangle("
        << m_p1 << ", "
        << m_p2 << ", "
        << m_p3 << ')';
    }
};
 
 
class Circle : public Shape
{
private:
    Point m_center;
    int m_radius{};
public:
    Circle(const Point& center, int radius):
        m_center{ center },
        m_radius{ radius }
    {
    }
    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", radius " << m_radius << ')';
        return out;
    }
    int getRadius() const
        { return m_radius; }
};
 
int getLargestRadius(const std::vector<Shape*>& v)
{
    int largestRadius{ 0 };
    for (const auto* element : v)
    {
        if (auto* c{ dynamic_cast<const Circle*>(element) })
        {
            largestRadius = std::max(largestRadius, c->getRadius());
        }
    }
    return largestRadius;
}

int main()
{
    std::vector<Shape*> v{
      new Circle{Point{1, 2, 3}, 7},
      new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
      new Circle{Point{4, 5, 6}, 3}
    };
 
    // здесь выводим каждую фигуру в векторе v в отдельной строке
 
    //                                       напишите ↓ эту функцию
    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; 
 
    // здесь удаляем каждый элемент вектора
 
    return 0;
}