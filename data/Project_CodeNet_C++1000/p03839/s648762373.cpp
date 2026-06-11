#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    priority_queue<int> pq;
    int a[n];
    int sumpos = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) sumpos += a[i];
    }
    int lp = 0;
    int rp = 0;
    int cur = 0;
    for (int i = 0; i < k; i++) {
        cur += a[rp];
        if (a[rp] > 0) sumpos -= a[rp];
        rp++;
    }
    int best = cur + sumpos;
    while (rp != n) {
        cur += a[rp];
        if (a[rp] > 0) sumpos -= a[rp];
        rp++;
        cur -= a[lp];
        if (a[lp] > 0) sumpos += a[lp];
        lp++;
        if (cur+sumpos > best) {
            best = cur+sumpos;
        }
        if (sumpos > best) {
            best = sumpos;
        }
    }
    cout << max(best, (int)0) << '\n';
}
/*

 */