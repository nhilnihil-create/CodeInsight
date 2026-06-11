#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long n, k;
    map<long long, long long> m;

    cin >> n >> k;

    long long a, b;
    for (long long i = 0; i < n; i++) {
        cin >> a >> b;
        m[a] += b;
    }

    for (auto itr : m) {
        k -= itr.second;
        if (k <= 0) {
            cout << itr.first;
            return 0;
        }
    }
    //
}
