#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

//pow(llpow,modpow)
template<class T> ll llpow(ll x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
long long modpow(long long a, long long n, long long mod) {long long res = 1;while (n > 0) {if (n & 1) res = res * a % mod;a = a * a % mod;n >>= 1;}return res;}
//最大公約数
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
//最小公倍数
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}
//逆元
long long modinv(long long a, long long m) {long long b = m, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}

#define rep(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)

long long INF = 1LL<<60;
int main( ){
    ll n;
    cin>>n;
    vll a(n);
    rep(i,0,n)cin>>a[i];
    ll mod=1e9+7;
    sort(a.begin(),a.end());
    bool check=true;
    if(n%2){
        for(ll i=0;i<(n-1)/2;i++){
            ll left=i*2+1;
            if(a[left]==a[left+1])continue;
            else {
                check=false; break;
            }
        }
    }
    else {
        for(ll i=0;i<n/2;i++){
            ll left=i*2;
            if(a[left]==a[left+1])continue;
            else {
                check=false; break;
            }
        }
    }
    if(check){
        ll ans;
        if(n%2){
            ans=modpow(2,(n-1)/2,mod);
        }
        else {
            ans=modpow(2,n/2,mod);
        }
        cout<<ans<<endl;
    }
    else {
        cout<<0<<endl;
    }
    return 0;
}


