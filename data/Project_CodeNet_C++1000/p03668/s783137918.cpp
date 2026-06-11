#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u,v;cin>>u>>v;u--,v--;
        g[u].push_back(v);g[v].push_back(u);
    }    
    function<int(int,int)> dfs=[&](int pre,int now){
        int ret=0;
        for(auto &to:g[now])if(to!=pre)ret^=dfs(now,to)+1;
        return ret;
    };
    cout<<(dfs(-1,0)==0?"Bob\n":"Alice\n");
    return 0;
}
