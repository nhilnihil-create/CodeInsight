#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define put(a) cout<<a<<"\n"
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
#define SZ(x) ((ll)(x).size())
typedef long long ll;
typedef pair<int, int> P;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b){a=b;return 1;}return 0;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b){a=b;return 1;}return 0;}

int euc(int a,int b){
    if(a%b==0){
        return b;
    }else if(b%a==0){
        return a;
    }else if(a>b){
        return euc(b,a%b);
    }else{
        return euc(a,b%a);
    }
}

template<typename T>
T gcd(T u, T v) {
    if(u==0)return v;
    if(v==0)return u;
    T r;
    while (v) {
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}

int main(){
    ll n,x;
    cin >> n >> x;
    ll res = 0;
    res += n;
    ll a = x;
    ll b = n-x;
    ll r;
    while(a){
        res += b/a*a*2;
        r = b%a;
        b = a;
        a = r;
    }
    res -= b;
    put(res);
    return 0;
}
