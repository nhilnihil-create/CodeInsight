#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i < n; i++)
#define repv(i,n) for(int i = n-1; i >= 0; i--)
#define fi first
#define sc second
#define pb push_back
using namespace std;
typedef long long ll;

char BUF[3500000];
inline void I(int&a){scanf("%d",&a);}
inline void I(int&a,int&b){scanf("%d%d",&a,&b);}
inline void I(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void I(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void L(ll&a){scanf("%lld",&a);}
inline void L(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void L(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void L(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void S(string&str){str.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)str.pb(BUF[i]);}
inline void SV(vector<int>&v){v.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)if('a'<=BUF[i]&&BUF[i]<='z')v.pb(BUF[i]-'a');else v.pb(BUF[i]-'A');}

const auto EPS = 1e-10;
const auto INF = 100000000;
const auto MOD = 1000000007;
typedef pair<ll,ll> P;

ll n;
ll x[100000];
ll kai[100001];

int main(){
    kai[0] = 1;
    for(ll i = 1; i <= 100000; i++) kai[i] = kai[i-1]*i%MOD;
    L(n);
    rep(i,n) L(x[i]);
    rep(i,n) x[i]--;
    ll ans = 1;
    ll sum = 0;
    sum = 1;
    for(int i = 1; i < n; i++){
        if(sum*2 == x[i]+1){
            ans = ans*(sum+1)%MOD;
        } else if(sum > (x[i]+1)/2){
            ans = ans*sum%MOD;
        } else sum++;
    }
    ans = ans*kai[sum]%MOD;
    cout << ans << endl;
}






























