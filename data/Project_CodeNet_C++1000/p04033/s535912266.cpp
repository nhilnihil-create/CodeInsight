#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < 0) {
        if (b < 0) {
            if ((a-b)%2) {
                cout << "Positive" << endl;
            } else {
                cout << "Negative" << endl;
            }
        } else {
            cout << "Zero" << endl;
        }
    } else {
        if (b < 0) {
            cout << "Zero" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}

