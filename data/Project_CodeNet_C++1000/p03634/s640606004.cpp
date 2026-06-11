#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll DP[100005];
vector<vector<pair<int, ll> > > edge(100005);

void solve(int u, int v){
    if(DP[v]>-1) return ;
    if(u==-1) {
        DP[v] = 0;
    }
    for(int i=0;i<edge[v].size();++i){
        if(edge[v][i].fi==u) DP[v] = DP[u] + edge[v][i].se;
    }
    for(int i=0;i<edge[v].size();++i){
        if(DP[edge[v][i].fi]>0) continue;
        solve(v, edge[v][i].fi);
    }
}

int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        DP[i] = -1;
    }
    int a, b;
    ll c;
    for(int i=0;i<N-1;++i){
        cin>>a>>b>>c;
        a--;
        b--;
        edge[a].push_back(mp(b, c));
        edge[b].push_back(mp(a, c));
    }
    int Q, K;
    cin>>Q>>K;
    K--;
    solve(-1, K);
    int x, y;
    ll ans[Q];
    for(int i=0;i<Q;++i){
        cin>>x>>y;
        x--;
        y--;
        ans[i] = DP[x] + DP[y];
    }
    for(int i=0;i<Q;++i){
        cout<<ans[i]<<endl;
    }
}

