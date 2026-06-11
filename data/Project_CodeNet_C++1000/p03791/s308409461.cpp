#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll n;
ll f(vector<ll> v,ll k){
    ll ki=v[k-1];
    ll now=ki+1;
    ll ret=n;
    rep(i,k,n+1){
        if(v[i]>=now){
            now+=2;
        }
        else{
            ret=i;
            break;
        }
    }
    return ret;
}
int main(){
    cin>>n;
    vector<ll> v(n);rep(i,0,n)cin>>v[i];
    v.insert(v.begin(),0);
    ll now=1;
    ll ans=1;
    ll cnt=0;
    for(;;){
        ll g=n;
        ll ki=v[now-1];
        ll ss=ki+1;
        rep(i,now,n+1){
            if(v[i]>=ss){
                ss+=2;
            }
            else{
                g=i;
                break;
            }
        }
        //cout<<g<<" ";
        if(g==n){
            if(n==cnt)break;
            rrep(i,n-cnt,1){
                ans*=i;
                ans%=mod;
            }
            break;
        }
        ans*=(g-cnt+mod)%mod;
        cnt++;
        now=g+1;
        ans%=mod;
    }
    cout<<ans<<endl;
}
