#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n+m; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a==b+c) {
        cout << "Yes" << endl;
    } else if (b==a+c) {
        cout << "Yes" << endl;
    } else if (c==a+b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
