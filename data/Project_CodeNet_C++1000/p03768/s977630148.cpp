#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, Q;

vector<ll>path[101010];
ll V[101010], D[101010], C[101010];
ll flg[101010][15];
ll ans[101010];

void dfs(ll v, ll d, ll c){
    if(flg[v][d])return;
    if(ans[v] == 0)ans[v] = c;
    flg[v][d] = c;
    if(d == 0)return;
    for(ll i = 0; i < path[v].size(); i++){
        ll to = path[v][i];
        if(flg[to][d - 1])continue;
        dfs(to, d - 1, c);
    }
}

int main(){
    
    cin >> N >> M;
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    cin >> Q;
    for(ll i = 1; i <= Q; i++)cin >> V[i] >> D[i] >> C[i];
    for(ll i = Q; i >= 1; i--)dfs(V[i], D[i], C[i]);
    for(ll i = 1; i <= N; i++)cout << ans[i] << endl;
    
    return 0;
}