#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,k;
    cin >> n >>k;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    vector<ll>init_a(n);
    rep(i,n) init_a[i] = a[i];
    ll ans = 1e18;
    for(int bit = 0;bit < (1<<n);bit++) {
        ll tmp = 0;
        ll cnt = 0;
        for(int i = 0;i<n;i++) {
            if(bit & (1<<i)) {
                ll maxh = 0;
                for(int j = 0;j<i;j++) {
                    maxh = max(maxh,a[j]);
                }
                if(maxh >= a[i]) {
                    tmp = tmp + maxh - a[i] + 1;
                    a[i] += maxh - a[i] + 1;
                }
                cnt++;
            }
        }
        if(cnt == k) {
            ans = min(ans,tmp);
        }
        rep(i,n) a[i] = init_a[i];
    }
    cout << ans << endl;
}