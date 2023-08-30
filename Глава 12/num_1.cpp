#include <iostream>
#include <cmath>
 
class Point2d
{
private:
    double m_x{};
    double m_y{};
public:
    Point2d(double x = 0, double y = 0): m_x{ x }, m_y{ y }
    {
    }
    
    void print()
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double getX()
    {
        return m_x;
    }
    double getY()
    {
        return m_y;
    }

    /*
    double distanceTo(Point2d point)
    {
        return std::sqrt((m_x-point.m_x)*(m_x-point.m_x)+(m_y-point.m_y)*(m_y-point.m_y));
    }
    */
};

double distanceFrom(Point2d point1, Point2d point2)
{
    double x1{ point1.getX() };
    double y1{ point1.getY() };
    double x2{ point2.getX() };
    double y2{ point2.getY() };
    
    return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: "
              << distanceFrom(first, second) << '\n';
 
    return 0;
}