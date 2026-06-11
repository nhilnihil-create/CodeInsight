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
    ll n, m, ans=0;
    cin >> n >> m;
    if(abs(n-m) > 1){
        puts("0");
        return 0;
    }
    bool d=false, w=false, dw=false;;
    if(n < m) d = true; 
    if(n > m) w = true;
    if(n == m) dw = true;
    ll dog=1, wolf=1;
    if(d){ //dog
        rep(i,m){
            dog *= (n+1-i);
            dog %= mod;
        }
        rep(i,n){
            dog *= (n-i);
            dog %= mod;
        }
        ans += dog%mod;
        ans %= mod;
    }
    if(w){ //wolf
        rep(i,n){
            wolf *= (m+1-i);
            wolf %= mod;
        }
        rep(i,m){
            wolf *= (m-i);
            wolf %= mod;
        }
        ans += wolf%mod;
        ans %= mod;
    }
    if(dw){
        rep(i,m){
            dog *= (n-i);
            dog %= mod;
        }
        rep(i,n){
            dog *= (n-i);
            dog %= mod;
        }
        ans += dog%mod;
        ans %= mod;
        rep(i,n){
            wolf *= (m-i);
            wolf %= mod;
        }
        rep(i,m){
            wolf *= (m-i);
            wolf %= mod;
        }
        ans += wolf%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
