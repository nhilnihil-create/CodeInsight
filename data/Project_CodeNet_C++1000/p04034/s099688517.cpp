#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<cmath>
#include<math.h>
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
const ll inf=1e9+7;
const ll mod=1e9+7;
const double PI=M_PI;
signed main(){
    ll n,m;cin>>n>>m;
    vector<ll>sz(n,1);
    vector<ll>now(n);
    now[0]=1;
    rep(i,m){
        ll x,y;cin>>x>>y;
        x--;y--;
        if(now[x]>0){
            now[y]=sz[y]+1;
            now[x]--;
        }
        sz[x]--;
        sz[y]++;
        if(now[y]>0){
            now[y]=sz[y];
        }
    }
    ll ans=0;
    rep(i,n){
        if(now[i]>0)ans++;
    }
    cout<<ans<<endl;
}