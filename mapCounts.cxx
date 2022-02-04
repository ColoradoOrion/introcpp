#include <map>
#include <iostream>

using std::cout;

class Prober
{
public:
    std::map<std::string, size_t> _switchCounts{{"PrimaryWiFiToSecondaryLTE", 0}, {"PrimaryLTEToSecondaryWiFi", 0}, {"SecondaryWiFiToPrimaryLTE", 0}, {"SecondaryLTEToPrimaryWiFi", 0}};

    void
    GetSwitchCounts(std::map<std::string, size_t> &results)
    {
        cout << "map size: " << _switchCounts.size() << std::endl;

        // copy the map
        results = _switchCounts;

        cout << "result size: " << _switchCounts.size() << std::endl;
        // reset the counters
        _switchCounts = std::map<std::string, size_t>{{"PrimaryWiFiToSecondaryLTE", 0}, {"PrimaryLTEToSecondaryWiFi", 0}, {"SecondaryWiFiToPrimaryLTE", 0}, {"SecondaryLTEToPrimaryWiFi", 0}};
    };

    void
    IncrementCount(const std::string &key)
    {
        _switchCounts[key] += 1;
    }
};

int main()
{
    Prober prober;

    prober.IncrementCount("PrimaryWiFiToSecondaryLTE");

    std::map<std::string, size_t> counts;

    prober.GetSwitchCounts(counts);

    cout << "outside map size: " << counts.size() << std::endl;

    for (auto &kvp : counts)
    {
        cout << kvp.first << " is " << kvp.second << std::endl;
    }
}