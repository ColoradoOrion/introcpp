#include <iostream>
#include <utility>

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a{20};
    int b{30};

    double c{3};
    double d{5};

    std::cout << "a: " << a << " b: " << b << std::endl;
    Swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::swap(a, b);
    std::cout << "a: " << a << " b: " << b << std::endl;

    std::cout << "c: " << c << " c: " << c << std::endl;
    Swap(c, d);
    std::cout << "c: " << c << " c: " << c << std::endl;
}