#include <iostream>

using namespace std;

double CelsiusFromFahrenheit(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main()
{
    double fahrenheit{};
    double celsius{};

    cout << "Please enter a temperature in Fahrenheit: ";
    cin >> fahrenheit;

    celsius = CelsiusFromFahrenheit(fahrenheit);

    cout << "The corresponding value in Celcius is: " << celsius << '\n';
}