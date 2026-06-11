#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    ll n,m;cin>>n>>m;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<ll>b(2*m+1);
    vector<ll>c(2*m+1);
    ll sum=0;
    REP(i,1,n){
        ll x=a[i-1];
        ll y=a[i];
        if(y<x)y+=m;
        b[x+2]++;
        b[y+1]--;
        c[y+1]-=y-x-1;
        sum+=y-x;
    }
    REP(i,1,2*m+1)b[i]+=b[i-1];
    ll ma=0;
    REP(i,1,2*m+1){
        b[i]+=b[i-1]+c[i];
        //cout<<b[i]<<endl;
    }
    REP(i,1,m+1){
        b[i]+=b[i+m];
        ma=max(b[i],ma);
        //cout<<b[i]<<endl;
    }
    cout<<sum-ma<<endl;
}