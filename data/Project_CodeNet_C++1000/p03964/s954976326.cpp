#include "bits/stdc++.h"
using namespace std;
static const int MAX = 1000;

int main() {
    int n;
    cin >> n;

    long long T, A;
    cin >> T >> A;

    for (int i = 1; i < n; ++i) {
        int t, a; cin >> t >> a;
        long long dt = (T + t - 1) / t;
        long long da = (A + a - 1) / a;
        long long d = max(dt, da);
        T = t * d;
        A = a * d;
    }

    cout << T + A << endl;

    return 0;
}
