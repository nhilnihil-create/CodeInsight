#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    map<long long, long long> bars;
    for (long long i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        if (bars.count(A) == 0) {
            bars.insert(make_pair(A, 0));
        }
        ++bars[A];
    }

    long long longLength = 0;
    long long shortLength = 0;
    for (map<long long, long long>::const_reverse_iterator rit = bars.rbegin(); rit != bars.rend(); ++rit) {
        long long n = rit->second;
        long long length = rit->first;
        if (n >= 4 && longLength == 0) {
            longLength = length;
            shortLength = length;
            break;
        }
        if (n >= 2) {
            if (longLength == 0) {
                longLength = length;
                continue;
            }
            else if (shortLength == 0) {
                shortLength = length;
                break;
            }
        }
    }
    long long s = longLength * shortLength;
    cout << s << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
