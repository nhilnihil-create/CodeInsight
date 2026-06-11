#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}


int main(void)
{
    ll n, m, ans=1;
    cin >> n >> m;
    if(abs(n-m) > 1){
        puts("0");
        return 0;
    }
    rep(i,n){
        ans *= (n-i);
        ans %= mod;
    }
    rep(i,m){
        ans *= (m-i);
        ans %= mod;
    }
    if(n == m) ans *=2;
    cout << ans%mod << endl;
    return 0;
}
