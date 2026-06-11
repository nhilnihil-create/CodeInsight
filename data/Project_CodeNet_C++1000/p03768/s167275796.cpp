#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, M, Q;
int v[100100], d[100100], c[100100];
int dp[100100][11];
int col[100100];
vector<int> G[100100];

void dfs(int V, int D, int C)
{
    if(~dp[V][D]){
        return;
    }
    dp[V][D] = 0;
    if(col[V] == 0){
        col[V] = C;
    }
    if(D == 0)return;
    for(int i = 0; i < (int)G[V].size(); i++){
        int to = G[V][i];
        dfs(to, D - 1, C);
    }
    return;
}

signed main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    memset(dp, -1, sizeof(dp));
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> v[i] >> d[i] >> c[i];
    }
    for(int i = Q - 1; i >= 0; i--){
        v[i]--;
        dfs(v[i], d[i], c[i]);
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", col[i]);
    }



    return 0;
}
