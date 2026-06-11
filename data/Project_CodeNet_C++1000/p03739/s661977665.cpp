#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll s = a[0];
    ll ans1 = 0, ans2 = 0;
    if (s <= 0) {
        ans1+=-s+1;
        s=1;
    }
    rep2(i, 1, n) {
        if (i%2 && s+a[i] >= 0) {
            ans1 += s+a[i]+1;
            s = -1;
        }
        else if (i%2==0 && s+a[i] <= 0) {
            ans1 += -(s+a[i]) + 1;
            s = 1;
        }
        else s += a[i];
    }
    s = a[0];
    if (s >= 0) {
        ans2+=s+1;
        s=-1;
    }
    rep2(i, 1, n) {
        if (i%2==0 && s+a[i] >= 0) {
            ans2 += s+a[i]+1;
            s = -1;
        }
        else if (i%2 && s+a[i] <= 0) {
            ans2 += -(s+a[i]) + 1;
            s = 1;
        }
        else s += a[i];
    }
    cout << min(ans1, ans2) << endl;
}
