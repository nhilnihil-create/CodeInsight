#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

int main() {
    vector<ll> a(3); REP(i, 3) cin >> a[i];

    if ((a[0] % 2) * (a[1] % 2) * (a[2] % 2) == 0)
        cout << 0 << endl;
    else {
        sort(a.begin(), a.end());
        cout << a[0] * a[1] << endl;
    }

    return 0;
}