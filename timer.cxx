#include <unistd.h>
#include <iostream>

#include <cstddef>
#include <mutex> // std::mutex, std::lock_guard
#include <chrono>

using std::mutex;
using std::size_t;
using std::chrono::milliseconds;
using std::chrono::steady_clock;

class MetricSummary
{
private:
    // how many samples do we have?
    size_t _count{0};

    // slowest time we recorded
    double _max{0};

    // fasted time we recorded
    double _min{0};

    // total time recorded
    double _total{0};

    mutex _mutex;

public:
    MetricSummary(){};

    void Read(double &average, size_t &count, double &max, double &min)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        average = _count > 0 ? (double)_total / (double)_count : 0;
        count = _count;
        max = _max;
        min = _min;
    }

    void ReadAndReset(double &average, size_t &count, double &max, double &min)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        average = _count > 0 ? (double)_total / (double)_count : 0;
        count = _count;
        max = _max;
        min = _min;

        _total = 0;
        _count = 0;
        _max = 0;
        _min = 0;
    }

    void AddDuration(const steady_clock::time_point start, const steady_clock::time_point end)
    {
        std::lock_guard<std::mutex> lock(_mutex);

        std::chrono::duration<double, std::milli> duration = end - start;
        double milliseconds = duration.count();
        _max = std::max(_max, milliseconds);
        _min = std::min(_min, milliseconds);
        ++_count;
        _total += milliseconds;
    }
};

int main()
{

    MetricSummary metrics;
    double average{0};
    double max{0};
    double min{0};
    size_t count{0};

    std::cout << "starting..." << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "loop " << i << std::endl;

        auto start = steady_clock::now();
        sleep(1);
        auto end = steady_clock::now();

        metrics.AddDuration(start, end);
    }

    metrics.Read(average, count, max, min);

    std::cout << "Avg: " << average << " count: " << count << " max: " << max << " min: " << min << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        std::cout << "loop " << i << std::endl;
        auto start = steady_clock::now();
        sleep(1);
        auto end = steady_clock::now();

        metrics.AddDuration(start, end);
    }

    metrics.ReadAndReset(average, count, max, min);

    std::cout << "Avg: " << average << " count: " << count << " max: " << max << " min: " << min << std::endl;

    metrics.ReadAndReset(average, count, max, min);

    std::cout << "Avg: " << average << " count: " << count << " max: " << max << " min: " << min << std::endl;
}