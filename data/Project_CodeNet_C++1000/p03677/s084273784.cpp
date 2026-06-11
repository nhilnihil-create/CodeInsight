#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MN = 200010;
int n, m;
int a[MN];
ll s1[MN], s2[MN];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    ll sm = 0;
    for (int i = 0; i < n-1; i++) {
        int l = a[i], r = a[i+1];
        int d = r - l;
        if (d < 0) d += m;
        sm += d;
        if (l < r) {
            s1[l+1]++;
            s2[l+1] += l+1;
            s1[r+1]--;
            s2[r+1] -= l+1;
        } else  {
            s1[l+1]++;
            s2[l+1] += l+1;
            s1[r+m+1]--;
            s2[r+m+1] -= l+1;
        }
    }
    for (int i = 0; i < 2*m-1; i++) {
        s1[i+1] += s1[i];
        s2[i+1] += s2[i];
    }

    ll ma = 0;
    for (int i = 0; i < m; i++) {
        ll cur = i * s1[i] - s2[i] + (i+m) * s1[i+m] - s2[i+m];
        ma = max(ma, cur);
    }
    cout << sm - ma << endl;
    return 0;
}