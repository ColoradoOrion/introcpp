#include <iostream>
#include <stdio.h>
#include <vector>
#include <chrono>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main()
{
    cout << "Sleeping..." << endl;
    cout << "Precision: " << chrono::steady_clock::period::den << endl;

    /*  auto start = chrono::high_resolution_clock::now();
    auto stStart = chrono::steady_clock::now();

    sleep(4);

    auto finish = chrono::high_resolution_clock::now();
    auto stFinish = chrono::steady_clock::now();
    auto duration = finish - start; 

    double time = (stFinish - stStart).count() / 1000000.0;

    cout << "Hello, World! I slept for " << endl << duration.count() << endl << time << endl;
*/

    // Looping
    vector<chrono::steady_clock::time_point> sentTs(10);
    for (int i = 0; i < 10; ++i)
    {
        auto now = chrono::steady_clock::now();
        cout << "Storing " << now.time_since_epoch().count() << endl;
        sentTs.at(i) = now;
    }

    cout << "------------" << endl;

    auto finish = chrono::steady_clock::now();

    for (int i = 0; i < 10; ++i)
    {
        auto duration = finish - sentTs.at(i);
        auto byTimeSince = finish - sentTs.at(i).time_since_epoch();
        cout << "duration: " << endl 
        << duration.count() << endl 
        << byTimeSince.time_since_epoch().count() << endl;
    }


}