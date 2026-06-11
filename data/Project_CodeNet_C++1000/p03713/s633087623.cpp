#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF 1e18
#define INF 1e9
using namespace std;

#define P pair<ll,ll>
#define fs first
#define sc second

signed main(){
    ll h,w;
    cin >> h >> w;
    ll ans = min(h,w);
    if(h % 3 == 0 || w & 3 == 0){
        cout << 0 << endl;
        return 0;
    }

    rep(i,1,h){
        ll temp = max(abs((h-i)*w - i*(w/2)),abs((h-i)*w - i*(w - w/2)));
        ans = min(ans,temp);
    }

    swap(h,w);

    rep(i,1,h){
        ll temp = max(abs((h-i)*w - i*(w/2)),abs((h-i)*w - i*(w - w/2)));
        ans = min(ans,temp);
    }

    cout << ans << endl;
    ll ans2;
    
    return 0;
}