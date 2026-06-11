#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int a[20];

int main()
{
    int n, k;
    cin >> n >> k;
    rep(i,n) cin >> a[i];

    ll ans = ll(1e18)+1;
    rep(bit,1<<n) {
        ll tot = 0;
        int maxv = 0;
        int visible = 0;
        rep(i,n) {
            if (maxv < a[i]) {
                visible++;
                maxv = a[i];
            } else if (bit>>i&1) {
                tot += (maxv - a[i]) + 1;
                visible++;
                maxv++;
            }
        }
        if (visible >= k) ans = min(ans, tot); 
    }
    cout << ans << endl;

    return 0;
}