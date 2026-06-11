#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, amax = 0, amin = 1e6;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        amax = max(amax, a[i]);
        amin = min(amin, a[i]);
    }
    if (amax - amin >= 2) {
        puts("No");
        return 0;
    }

    if (amax - amin == 0) {
        bool can1 = true, can2 = true;
        rep(i, n) {
            if (a[i] != n - 1) can1 = false;
            if (2 * a[i] > n) can2 = false;
        }
        puts((can1 || can2) ? "Yes" : "No");
        return 0;
    }
    int x = 0, y = 0;
    rep(i, n) {
        if (a[i] == amax - 1)
            x++;
        else if (a[i] == amax)
            y++;
    }
    puts((x + y == n && x < amax && 2 * (amax - x) <= y) ? "Yes" : "No");
}