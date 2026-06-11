//----------------------------------------------------------------------
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
    rep(i, n)
        cin >> a[i];

    ll ans = 1e18;
    for(int bit = 0; bit < (1 << n); ++bit) {
        vector<ll> tmpa(a);
        vector<int> seebull = {0};
        for(int i = 1; i < n; ++i) {
            if(bit & ( 1 << i)) {
                seebull.push_back(i);
            }
        }
        if((int)seebull.size() != k) continue;

        ll sum = 0;
        for(int i = 0; i < k; ++i) {
            int tmpbull = seebull[i];
            ll maxheight = 0;
            for(int j = 0; j < tmpbull; ++j) {
                maxheight = max(maxheight, tmpa[j]);
            }
            ll add = 0;
            if(maxheight >= tmpa[tmpbull]) {
                add = maxheight - tmpa[tmpbull] + 1;
                tmpa[tmpbull]  += add;
            }
            sum += add;
        }
        ans = min(sum, ans);
    }
    cout << ans << endl;
    return 0;
}
