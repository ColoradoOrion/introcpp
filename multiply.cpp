#include <iostream>
#include <random>

using std::cin;
using std::cout;
using namespace std;

int main()
{

    // Used to initialize (seed) the random number generator engine
    random_device seed{};

    // Random number generator
    mt19937 engine{seed()};

    // Uniformly distribute random numbers in [1..10]
    uniform_int_distribution<> distribution{1, 10};

    int questionCount{};
    int correctAnswers{};
    bool askMore{true};

    while(askMore)
    //for (int q{}; q < questionCount; ++q)
    {
        int a{distribution(engine)};
        int b{distribution(engine)};
        questionCount++;

        cout << a << " * " << b << " = ? ";

        int userAnswer{};
        cin >> userAnswer;

        if (userAnswer == (a * b))
        {
            cout << "Correct!\n";
            ++correctAnswers;
        }
        else
        {
            cout << "Wrong! Answer is " << (a * b) << "\n";
        }

        cout << "Continue (y/n)? ";
        char ch{};
        cin >> ch;
        askMore = ch == 'y' || ch == 'Y';
    }

    cout << "Correct answers: " << correctAnswers << '\n';

    if(correctAnswers == questionCount){
        cout << "Congratulations! Your answers were all correct!\n";
    }
}