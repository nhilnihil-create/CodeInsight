#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define PI       3.1415926535897932384626433832795028841971
#define INF      100000000
#define EPS      1e-10
#define MOD      1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll n, m;
ll x[100001];
ll hoge[100001];
map<ll,ll> ma;
map<ll,ll>::iterator it;

int main(){
    cin >> n >> m;
    rep(i,n){
        ll y;
        cin >> y;
        ma[y]++;
        x[y%m]++;
    }
    for(it = ma.begin(); it != ma.end(); it++){
        ll p = (*it).first, q = (*it).second;
        hoge[p%m] += q/2;
    }
    ll ans = 0;
    rep(i,m-1){
        if((i+1)*2 == m){
            ans += x[i+1]/2;
            x[i+1] %= 2;
            continue;
        }
        ans += min(x[i+1],x[m-i-1]);
        ll z = min(x[i+1],x[m-i-1]);
        x[i+1] -= z;
        x[m-i-1] -= z;
    }
    ans += x[0]/2;
    for(ll i = 1; i < m; i++){
        ans += min(hoge[i],x[i]/2);
    }
    cout << ans << endl;
}
