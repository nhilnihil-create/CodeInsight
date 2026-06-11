#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[100010][11];
vector<int> G[100010];

void dfs(int x, int c, int d) {
    //cout << x << " "<< c << " " << d << endl;
    if (dp[x][d]) return;
    dp[x][d] = c;
    if (d == 0) return;
    dfs(x, c, d - 1);
    for(auto next: G[x]) {
        dfs(next, c, d - 1); 
        
    }
}
int v[100010], d[100010], c[100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, M) {
        int a, b; 
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q; cin >> Q;
    rep(i, Q) {
        cin >> v[Q - i - 1] >> d[Q - i - 1] >> c[Q - i - 1];
    }
    rep(i, Q) {
        dfs(v[i], i + 1, d[i]);
    }
    rep(i, N) {
        cout << c[dp[i + 1][0] - 1] << endl;
    }

    return 0;
}
