#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;
    if (B <= A) {
        cout << "delicious" << endl;
    } else if (B <= A+X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    return 0;
}
