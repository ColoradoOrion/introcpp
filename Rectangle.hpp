// Rectangle.hpp

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
public:
    Rectangle() = default;

    Rectangle(double width, double height);

    double Width() const;
    double Height() const;

    void Width(double width);
    void Height(double height);

    double Area() const;
    double Perimeter() const;

    void Scale(double scaleFactor);

private:
    double _width{};
    double _height{};
};


#endif // RECTANGLE_HPP