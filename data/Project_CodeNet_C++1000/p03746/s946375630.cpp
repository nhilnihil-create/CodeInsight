#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
vector<vector<ll> >G(100010);
vector<ll>path1(0);
vector<ll>path2(0);
vector<ll>visited(100010);
ll cnt=0;
void dfs(ll i,ll p){
    visited[i]=1;
    ll cnt1=0;
    for(auto e:G[i]){
        if(visited[e])continue;
        if(cnt1&&i>1)break;
        if(i==1)cnt++;
        dfs(e,i);
        cnt1++;
    }
    if(cnt>2)return;
    if(cnt==1&&i>1)path1.pb(i);
    if(cnt==2&&i>1)path2.pb(i);
}
int main(){
    ll n,m;cin>>n>>m;
    rep(i,m){
        ll a,b;cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dfs(1,0);
    cout<<path1.size()+path2.size()+1<<endl;
    rep(i,path1.size()){
        cout<<path1[i]<<' ';
    }
    cout<<1<<' ';
    reverse(all(path2));
    rep(i,path2.size()){
        cout<<path2[i]<<' ';
    }
    cout<<endl;
}