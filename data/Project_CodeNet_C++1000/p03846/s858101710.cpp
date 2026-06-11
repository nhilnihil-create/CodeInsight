#include "bits/stdc++.h"

using namespace std;

long long MOD = 1000000007;

bool increment(map<long long, long long>& m, long long key) {
    if (m.count(key) == 0) {
        m.insert(make_pair(key, 0));
    }
    m[key] += 1;
    if (m[key] > 2) {
        return false;
    }
    return true;
}

long long pow2Mod(int n) { // pow(2, n) % MOD
    long long ret = 1LL;
    for (int i = 1; i <= n; ++i) {
        ret *= 2;
        ret %= MOD;
    }
    return ret;
}

void Main() {
    long long N;
    cin >> N;
    map<long long, long long> position;
    for (long long i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        if (N % 2 == 0) { // N : even
            if (a % 2 == 0) {
                cout << 0 << endl;
                return;
            }
            a -= 1;
            a /= 2;
            bool valid = increment(position, N / 2 - 1 - a);
            valid &= increment(position, N / 2 + a);
            if (!valid) {
                cout << 0 << endl;
                return;
            }
        }
        else { // N : odd
            if (a % 2 == 1) {
                cout << 0 << endl;
                return;
            }
            a /= 2;
            bool valid = increment(position, (N - 1) / 2 + a);
            valid &= increment(position, (N - 1) / 2 - a);
            if (!valid) {
                cout << 0 << endl;
                return;
            }
        }
    }

    if (N % 2 == 0) {
        cout << pow2Mod(N / 2) << endl;
    }
    else {
        if (position.count((N - 1) / 2) != 1) {
            cout << 0 << endl;
            return;
        }
        cout << pow2Mod((N - 1) / 2) << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
