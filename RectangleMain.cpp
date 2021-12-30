/**
 * Contains code that uses Rectangle class
 */

#include "Rectangle.hpp"
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