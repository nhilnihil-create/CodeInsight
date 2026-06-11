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
int main(){
    string s,t;cin>>s>>t;
    int n=s.size(),m=t.size();
    int q;cin>>q;
    int ss[n+1],st[m+1];
    ss[0]=0;st[0]=0;
    rep(i,0,n)ss[i+1]=(ss[i]+(s[i]-'A'+1))%3;
    rep(i,0,m)st[i+1]=(st[i]+(t[i]-'A'+1))%3;
    rep(i,0,q){
        int a,b,c,d;cin>>a>>b>>c>>d;
        int u=(ss[b]-ss[a-1]+3)%3;
        int v=(st[d]-st[c-1]+3)%3;
        if(u==v)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
