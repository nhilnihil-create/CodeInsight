#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;

signed main(){
    ll n,m;
    cin >> n >> m;
    ll x,y;
    bool flag[n] ={false};
    flag[0] = true;
    ll cnt[n];
    rep(i,0,n) cnt[i] = 1;

    rep(i,0,m){
        cin >> x >> y;
        cnt[x-1]--;
        cnt[y-1]++;
        if(flag[x-1]) flag[y-1] = true;
        if(cnt[x-1] == 0 && flag[x-1]) flag[x-1] = false;
    }

    ll ans = 0;
    rep(i,0,n){
        if(flag[i]) ans++;
    }
    cout <<ans << endl;
    return 0;
}
