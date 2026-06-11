#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9;
const ll mod=998244353;
signed main(){
    ll n;cin>>n;
    vector<ll>d(100);
    ll ma=0;
    rep(i,n){
        ll a;cin>>a;
        ma=max(ma,a);
        d[a]++;
    }
    bool f=1;
    rep(i,(ma+1)/2){
        if(d[i])f=0;
    }
    REP(i,(ma+1)/2,ma+1){
        if(d[i]==0)f=0;
    }
    if(ma%2){
        if(d[(ma+1)/2]!=2)f=0;
    }else{
        if(d[ma/2]!=1)f=0;
    }
    if(f)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}