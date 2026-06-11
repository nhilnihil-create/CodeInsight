//----------------------------------------------------------------------
#include <algorithm>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 1e18;

    for(int bit = 0; bit < (1 << n); ++bit) {
        vector<ll> copya(a);
        ll maxh = copya[0];
        int num = 0;
        ll tmp = 0;
        for(int i = 1; i < n; ++i) {
            if(bit & ( 1 << i )) {
                num++;
                if(copya[i] <= maxh) {
                    tmp += maxh - copya[i] + 1;
                    copya[i] += maxh - copya[i] + 1;
                }
            }
            maxh = max(copya[i],maxh);
        }
        if(num != k - 1) continue;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
