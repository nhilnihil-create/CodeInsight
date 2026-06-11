#include <bits/stdc++.h>
using namespace std;

using lint = long long;

lint n, a[100004], b[100004], h[100004];
lint ans[100004];

map<int, int> mp;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    lint s = 0;    
    mp[0] = n;
    for (int i=0, k=0; i<n; i++) {
        if (a[i] > k) {
            mp[a[i]] = i;
            k = a[i]; s = 0;
        }
        auto it = mp.lower_bound(a[i]); it--;
        int x = it -> second, y = next(it) -> second;

        ans[y] += a[i] - a[x];
        b[x]++;
    }

    for (auto i=mp.begin(); next(i) != mp.end(); i++) {
        h[next(i)->second] = next(i)->first - i->first;
    }

    s = 0;
    for (int i=n-1; ~i; i--) if (b[i]) {
        s += b[i];
        ans[i] += h[i] * s;
    }

    for (int i=0; i<n; i++) cout << ans[i] << '\n';
}