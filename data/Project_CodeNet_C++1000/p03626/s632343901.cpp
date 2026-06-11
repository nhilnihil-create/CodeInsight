#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
using vll=vector<ll>;
using vvll=vector<vll>;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using vb=vector<bool>;
using pii=pair<int,int>;
using vpii=vector<pair<int,int>>;
using plli=pair<ll,int>;
using vplli=vector<pair<ll,int>>;
using pllll=pair<ll,ll>;
using vpllll=vector<pair<ll,ll>>;

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
//試験導入
#define irep(i, end_i, begin_i) for (ll i = (ll)begin_i-1; i >= (ll)end_i; i--)

long long INF = 1LL<<60;
int main( ){
    ll n;
    cin>>n;
    string f,s;
    cin>>f>>s;
    int canuse=3;
    ll res=1;
    bool skip=false;
    // なし 0,-- 1,| 2
    int kind;
    int lkind=0;
    ll mod=1e9+7;
    rep(i,0,n){
        if(skip){
            skip=false;
            continue;
        }
        if(i+1<n&&s[i]==s[i+1]){
            skip=true;
            kind=1;
        }
        else{
            kind=2;
        }

        //今見ているブロックの形とその直前に見たブロックの形だけで値が決められるはず
        if(kind==1){
            if(lkind==0){
                res=res*6%mod;
            }
            else if(lkind==1){
                res=res*3%mod;
            }
            else{
                res=res*2%mod;
            }
            lkind=1;
        }
        else{
            if(lkind==0){
                res=res*3%mod;
            }
            else if(lkind==1){
                res=res%mod;
            }
            else{
                res=res*2%mod;
            }
            lkind=2;
        }
        if(res<0)res+=mod;
    }
    cout<<res<<endl;
    return 0;
}


