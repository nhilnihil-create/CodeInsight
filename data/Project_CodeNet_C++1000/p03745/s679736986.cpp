#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r = 1, st = 0;//-1 dec, 0 sin, 1 cre
    cin >> n;
    vector<int> d(n);
    for (int &i : d) cin >> i;
    for (int i = 1; i < n; i++) {
        if (st != 0 && (st > 0 && d[i] < d[i-1] || st < 0 && d[i] > d[i-1])) {st = 0, r++; continue;}
        if (d[i] > d[i-1] && !st) st = 1;
        else if (d[i] < d[i-1] && !st) st = -1;
    }
    cout << r << "\n";
    return 0;
}