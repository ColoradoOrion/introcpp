#include <cctype>
#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter a string to convert to upper case\n";

    std::string line{};

    std::getline(std::cin, line);

    for (auto c : line)
    {
        std::cout << (char)std::toupper(c);
    }

    std::cout << std::endl;
}