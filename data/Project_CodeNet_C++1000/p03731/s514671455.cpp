#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define vsort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())

const int MOD = 1000000007;
const int INF = INT_MAX;


// a,bの最小公倍数
ll lcm(ll a, ll b){ll lcm = a * b; ll r = a % b;while(r != 0){a = b; b = r; r = a % b;}return lcm /= b;}
// a,bの最大公約数
ll gcd(ll a, ll b){ll r = a % b;while(r != 0){a = b; b = r; r = a % b;}return b;}
// MOD
ll modadd(ll a, ll b){return (a%MOD+b%MOD+MOD)%MOD;}
ll modmul(ll a, ll b){return a%MOD*b%MOD%MOD;}
ll modexp(ll a, ll n){if(n==0)return 1; if(n%2==0){ll e=modexp(a,n/2); return modmul(e,e);} return modexp(a,n-1)*a%MOD;}
ll modinv(ll n){return modexp(n%MOD,MOD-2);}
ll modfact(ll n){ll res=1; for (int i=1; i <= n; ++i){res *= i; res %= MOD;} return res;}
ll modncr(ll n, ll r){ll numer=1;ll denom=1;for(int i=1;i<=r;++i){numer=modmul(numer,n-r+i);denom=modmul(denom,i);}return modmul(numer, modinv(denom));}


int main(){

    int n, T;
    cin >> n >> T;
    int t[n];
    rep(i,n) cin >> t[i];

    ll ans = 0; 
    rep(i,n-1) {
        if (T <= t[i+1] - t[i]) ans += T;
        else ans += t[i+1] - t[i];
    }
    ans += T;


    cout << ans << endl;
    





}



//              g++ -std=c++1z
