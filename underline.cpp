#include <string>
#include <iostream>

using namespace std;
void Underline(const std::string &s){
    const string underline(s.size(), '=');

    cout << s << endl;
    cout << underline << endl;
}

int main() {
    cout << "Enter a string: ";
    string input;

    getline(cin, input);

    cout << '\n';

    Underline(input);
}