#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()

using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;



const ll MOD = 1e9+7;
ll fac(ll n){
    ll ret=1;
    for(ll i=1;i<=n;i++){
        ret*=i;
        ret%=MOD;
    }
    return ret;
}
signed main(){
    ll n,m; cin >> n >> m;
    if(n==m){
        ll ans=fac(n);
        ans*=fac(m);
        ans*=2;
        ans%=MOD;
        cout << ans << endl;
    }else if(n+1==m){
        ll ans=fac(n);
        ans*=fac(m);
        ans%=MOD;
        cout << ans << endl;
    }else if(n==m+1){
        ll ans=fac(m);
        ans*=fac(n);
        ans%=MOD;
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }
}
