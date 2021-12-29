#include <algorithm> // for std::sort
#include <fstream>   // for file stream
#include <iostream>  // for cout
#include <string>
#include <vector>

using namespace std;

int main()
{
    // open file for reading
    ifstream file("data.txt");

    // read from file
    vector<string> lines{};
    string line;

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    // sort
    sort(begin(lines), end(lines));

    for (auto const &s : lines)
    {
        cout << s << endl;
    }
}