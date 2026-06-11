#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int n;
deque<int> b;
vector<int> ans;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    rep(i, n) {
        int a; cin >> a;
        if (i%2==0) b.pb(a);
        else b.push_front(a);
    }
    if (n%2==0) {
        while (b.size()) {
            int v = b.front(); b.pop_front();
            ans.pb(v);
        }
    }
    else {
        while (b.size()) {
            int v = b.back(); b.pop_back();
            ans.pb(v);
        }
    }
    rep(i, n) {
        if (i<n-1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}