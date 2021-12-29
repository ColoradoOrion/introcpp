#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::vector;
using std::string;

int main()
{
    vector<int> v{123, 125, 643, 6547, 23426};
    vector<string> names{"Andy", "Marnie", "Simon", "Lucie", "Brynley"};

    v.push_back(64);
    v.push_back(128);

    names.push_back("Luna");
    names.push_back("Senchu");
    names.push_back("Anna");
    names.push_back("Chi");

    cout << " Number of int elements: " << v.size() << '\n';

    cout << " vector's elements: ";

    for (const auto n : v)
    {
        cout << n << ' ';
    }

    cout << '\n';


        cout << " Number of name elements: " << names.size() << '\n';

    cout << " name vector's elements: ";

    for (const auto &n : names)
    {
        cout << n << ' ';
    }

    cout << '\n';
}