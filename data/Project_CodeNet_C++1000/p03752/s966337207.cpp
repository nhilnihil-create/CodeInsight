#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 1e18;
    for(int bit = 0; bit < (1<<n); bit++) {
        vector<ll> tmp;
        for(int i = 0; i < n; i++) {
            if(bit & (1<<i)) tmp.push_back(i);
        }
        if(tmp.size() < k) continue;
        ll pay = 0;
        ll itr = 0, i = 0, tmx = -100;
        rep(i, 0, n) {
            if(i == tmp[itr]) {
                pay += max(0LL, tmx - a[i] + 1);
                itr++;
                tmx = max(tmx+1, a[i]);
                if(itr == tmp.size()) break;
            } else {
                tmx = max(tmx, a[i]);
            }
        }
        ans = min(ans, pay);
    }
    cout << ans << endl;
    return 0;
}