class Rectangle
{
public:
    Rectangle() = default;

    Rectangle(double width, double height)
        : _width{width}, _height{height}
    {
    }

    double Width() const { return _width; }
    double Height() const { return _height; }

    void Width(double width) { _width = width; }
    void Height(double height) { _height = height; }

    double Area() const { return _width * _height; }
    double Perimeter() const { return 2.0 * (_width + _height); }

    void Scale(double scaleFactor)
    {
        _width *= scaleFactor;
        _height *= scaleFactor;
    }

private:
    double _width{};
    double _height{};
};

#include <iostream>

using namespace std;

void PrintInfo(const Rectangle &r)
{
    cout << "Rectangle width = " << r.Width()
         << ", height = " << r.Height()
         << ", area = " << r.Area()
         << ", perimeter = " << r.Perimeter()
         << "\n\n";
}

int main()
{
    cout << "Default constructed rectangle\n";
    Rectangle rl{};
    PrintInfo(rl);

    cout << "Rectangle r{10, 20}:\n";
    Rectangle r{10, 20};
    PrintInfo(r);

    cout << "After 2.5 scaling:\n";
    r.Scale(2.5);
    PrintInfo(r);
}