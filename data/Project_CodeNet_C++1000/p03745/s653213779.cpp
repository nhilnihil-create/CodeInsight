#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;cin>>n;
    ll ans = 0;
    ll now=-1, beg;
    rep(i,n){
        ll a;cin>>a;
        if(now==-1||(now-beg)*(a-now)<0){
            now=a;
            ans++;
            beg=a;
        }
        else now=a;
    }
    cout<<ans<<endl;
    return 0;
}