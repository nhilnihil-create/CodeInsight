#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod=7+1e9;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
ll qpow(ll a,ll b,ll p){a%=p; ll ret=1;for(;b;b>>=1,a=a*a%p) if(b&1) ret=ret*a%p; return ret;}
ll getInv(ll x,ll p){return qpow(x,p-2,p);}
const int N=5+2e5;
ll n[N];
ll C(ll a,ll b){ return n[a]*getInv(n[b]*n[a-b]%mod,mod)%mod;}
int main(){
    ll h,w,a,b; cin>>h>>w>>a>>b;
    n[0]=1;
    for(int i=1;i<N;i++) n[i]=n[i-1]*i%mod;
    ll ans=0;
    for(int i=b+1;i<=w;i++)
        ans=(ans+C(h-a-1+i-1,h-a-1)*C(a-1+w-i,w-i)%mod)%mod;
    ans=(ans+mod)%mod;
    cout<<ans<<'\n';
}