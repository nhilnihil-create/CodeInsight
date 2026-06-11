//
// Created by yjq on 2019/11/7.
//

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 2e5 + 10;
int n, a[maxn], r[maxn];

int c[maxn];

const int cmp(const int i, const int j) {
    return a[i] < a[j];
}

inline int lb(int x) { return x & -x; }

int read(int x) {
    int tot = 0;
    for (; x; x -= lb(x))tot += c[x];
    return tot;
}

void add(int x, int num) {
    for (; x <= n; x += lb(x))c[x] += num;
}

int main() {
    __;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        r[i] = i;
    }
    sort(r + 1, r + 1 + n, cmp);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = r[i];
        int left = 1, right = x;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (read(x) - read(mid - 1) == 0)right = mid;
            else left = mid + 1;
        }
        ll t1 = x - left + 1;
        left = x, right = n;
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (read(mid) - read(x) == 0)left = mid;
            else right = mid - 1;
        }
        ll t2 = right - x + 1;
        ans += t1 * t2 * a[x];
        add(x, 1);
    }
    cout << ans << endl;
    return 0;
}