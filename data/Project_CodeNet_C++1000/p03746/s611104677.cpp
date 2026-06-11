#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int n,m;
vector<vector<int>> g;
vector<bool> checked;
vector<int> a,b;

void dfs(int v,bool f){
    if(f) a.push_back(v);
    else  b.push_back(v);
    checked[v]=true;
    for(auto x:g[v]){
        if(checked[x]) continue;
        dfs(x,f);
        break;
    }
    return;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin>>n>>m;
    g.resize(n);
    checked=vector<bool>(n,false);
    rep(i,m){
        int a,b;
        cin>>a>>b;a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    checked[0]=true;
    int cnt=0;
    dfs(g[0][0],true);
    for(int i=0;i<g[0].size();i++){
        if(checked[g[0][i]]) continue;
        dfs(g[0][i],false);
        break;
    }
    vector<int> ans;
    reverse(ALL(a));
    for(auto x:a) ans.push_back(x);
    ans.push_back(0);
    for(auto x:b) ans.push_back(x);

    cout<<ans.size()<<endl;
    rep(i,ans.size()){
        cout<<ans[i]+1;
        cout<<(i==ans.size()-1?'\n':' ');
    }
    return 0;
}
