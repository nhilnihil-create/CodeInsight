//
// Created by yjq on 2019/11/13.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 2e5 + 10;
int n, a[maxn];
bool b[maxn];

bool check(int x) {
    for (int i = 1; i < n + n; ++i) {
        if (a[i] >= x)b[i] = 1;
        else b[i] = 0;
    }
    int l = n - 1, r = n + 1;
    for (; l >= 1 && r < n + n; --l, ++r) {
        if (b[l] == b[l + 1])return b[l];
        if (b[r] == b[r - 1])return b[r];
    }
    return (b[1] & b[n + n - 1]);
}

int main() {
    __;
    cin >> n;
    for (int i = 1; i < n + n; ++i)cin >> a[i];
    int l = 1, r = n + n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}