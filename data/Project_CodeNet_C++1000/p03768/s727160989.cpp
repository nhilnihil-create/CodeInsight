#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

bool dp[100010][15];
int N,M;
int Q;
vector<vector<int>> G;
vector<int> ans;

void solve(int v,int d,int c){
    if(d == -1) return;
    if(dp[v][d]) return;
    bool ok = false;
    rep(i,d+1){
        if(dp[v][i]) ok = true;
        dp[v][i] = true;
    }
    if(!ok) ans[v] = c;
    for(int u : G[v]){
        solve(u,d-1,c);
    }
}


int main(){
    cin >> N >> M;
    G.resize(N);
    ans.resize(N);
    rep(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> Q;
    vector<int> v(Q),d(Q),c(Q);
    rep(i,Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    rep(i,100010)rep(j,15) dp[i][j] = false;

    for(int i = Q-1; i >= 0; i--){
        solve(v[i],d[i],c[i]);
    }
    rep(i,N) cout << ans[i] << endl;

}