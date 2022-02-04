#include <vector>
#include <iostream>

// g++ -std=c++11 ./initVector.cpp -o ./initVector.exe

class ThingWithVector
{
public:
    int singleValue{0};
    std::vector<double> _v;

    ThingWithVector(size_t rows) : _v(rows, 1.23)
    {
        std::cout << "construction:" << std::endl;
        std::cout << _v.at(0) << std::endl;
    }

    void Print()
    {
        std::cout << "Print:" << std::endl;
        for (auto d : _v)
        {
            std::cout << d << std::endl;
        }

        std::cout << singleValue << std::endl;
    }
};

// Demonstrate initialization of vector with values
int main()
{
    std::vector<double> myVector(10, 5.2);

    for (auto d : myVector)
    {
        std::cout << d << std::endl;
    }

    ThingWithVector thing(3);
    thing.Print();
}