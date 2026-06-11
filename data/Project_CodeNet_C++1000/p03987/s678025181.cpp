#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int a[200100];
int idx[200100];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, N) idx[a[i]-1] = i;
    set<int> s;
    s.insert(-1);
    s.insert(N);
    int ans = 0;
    rep(i, N) {
        auto it = s.lower_bound(idx[i]);
        int r = *it;
        int l = *--it;
        ans += (i+1)*(idx[i]-l)*(r-idx[i]);
        s.insert(idx[i]);
    }
    cout << ans << endl;
}