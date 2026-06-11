#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vi=vector<int>;

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

vll table(1010,1);

ll mod=1e9+7;

bool is_prime(ll x){
    if(x<=1)return false;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}

long long INF = 1LL<<60;
int main( ){
    ll n;
    cin>>n;
    vll cnt(n+1,0);
    rep(i,1,n+1){
        if(is_prime(i)){
            rep(j,1,n+1){
                if(j%i==0){
                    ll t=j;
                    while(t%i==0){
                       t/=i;
                       cnt[i]++;
                    }
                }
            }
        }
    }
    ll res=1;
    rep(i,1,n+1){
        if(cnt[i]){
            res=res*(1+cnt[i])%mod;
            if(res<0)res+=mod;
        }
    }
    cout<<res<<endl;
    return 0;
}


