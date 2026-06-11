#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
long long extGCD(long long a,long long mod,long long &x,long long &y){
    if(mod==0){
        x=1;
        y=0;
        return a;
    }
    long long d=extGCD(mod,a%mod,y,x);//上に上がるときにswap(x,y)すると見る
    y-=(a/mod)*x;
    return d;
}
long long invmod(long long a,long long mod){
    long long x,y;
    extGCD(a,mod,x,y);
    x%=mod;
    if(x<0)x+=mod;
    return x;
}
ll fac[200010],finv[200010],inv[200010];
void combinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    REP(i,2,200010){
        fac[i]=fac[i-1]*i%inf;
        inv[i]=invmod(i,inf);
        finv[i]=finv[i-1]*inv[i]%inf;
    }
}
ll comb(ll n,ll k){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%inf)%inf;
}
int main(){
    int h,w,a,b;cin>>h>>w>>a>>b;
    combinit();
    ll ans=comb(h+w-2,h-1);
    ll cnt=0;
    rep(i,a){
        cnt=(cnt+comb(h-a+i+b-1,b-1)*comb(a-i-1+w-b-1,w-b-1)%inf)%inf;
    }
    ans-=cnt;
    if(ans<0)ans+=inf;
    cout<<ans<<endl;
}