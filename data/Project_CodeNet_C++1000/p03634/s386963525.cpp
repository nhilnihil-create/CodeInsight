#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
/* -- template -- */

ll d[100000];
vector<vector<pair<int, ll>>> G;
bool visited[100000];
void dfs(int K){
    visited[K] = true;
    for(pair<int, ll> a : G[K]){
        if(!visited[a.first]){
            d[a.first] = d[K] + a.second;
            dfs(a.first);
        }
    }
}
int main(){
    int N; cin >> N;
    G.resize(N);
    rep(i, N - 1){
        int a, b;ll c;cin >> a >> b >> c;--a;--b;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    int Q, K; cin >> Q >> K;--K;
    d[K] = 0;
    dfs(K);

    ll ans[Q];
    rep(i, Q){
        int x, y; cin >> x >> y;
        --x;--y;
        ans[i] = d[x] + d[y];
    }
    rep(i, Q)cout << ans[i] << endl;
}
