#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>t(n+2),a(n+1);
    rep(i,n)cin>>t[i+1];
    rep(i,n)cin>>a[i+1];
    vector<ll>mt(n+2);
    bool f=1;
    rep(i,n){
        if(t[i]!=t[i+1])mt[i+1]=t[i+1];
    }
    ll ma=0;
    for(int i=n;i>0;i--){
        ma=max(mt[i],ma);
        if(ma>a[i])f=0;
        if(a[i]!=a[i+1]){
            if(mt[i]>0&&mt[i]!=a[i])f=0;
            mt[i]=a[i];
        }
    }
    ll ans=1;
    ll k=1;
    rep(i,n){
        if(mt[i+1]){
        }else{
            ans*=min(a[i+1],t[i+1]);
            ans%=inf;
        }
    }
    cout<<(f?ans:0)<<endl;
}