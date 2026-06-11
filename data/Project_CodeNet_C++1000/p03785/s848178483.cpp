#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n, c, k;
    cin >> n >> c >> k;
    vector<unsigned long long> arrive_time(n);
    for (unsigned long long i = 0; i < n; ++i) cin >> arrive_time[i];
    sort(arrive_time.begin(), arrive_time.end());
    size_t num_bus = 0;
    unsigned long long passengers = 0;
    double start_time = .0;
    for(unsigned long long i = 0; i < n; ++i) {
        if (passengers == 0) {
            start_time = arrive_time[i];
            ++passengers;
            ++num_bus;
        }
        else if (arrive_time[i] - start_time <= k) {
            ++passengers;
        }
        else {
            start_time = arrive_time[i];
            passengers = 1;
            ++num_bus;
        }

        if (passengers == c) {
            passengers = 0;
        }
    }

    cout << num_bus << endl;
    return EXIT_SUCCESS;
}