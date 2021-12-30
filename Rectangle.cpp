// Rectangle.cpp - Rectangle implementation

#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
    : _width{width}, _height{height} {}

double Rectangle::Width() const {
    return _width;
}

void Rectangle::Width(double width) {
    _width = width;
}

double Rectangle::Height() const {
    return _height;
}

void Rectangle::Height(double height) {
    _height = height;
}

double Rectangle::Area() const {
    return _width * _height;
}

double Rectangle::Perimeter() const {
    return 2.0 * (_width + _height);
}

void Rectangle::Scale(double scaleFactor) {
    _width *= scaleFactor;
    _height *= scaleFactor;
}
