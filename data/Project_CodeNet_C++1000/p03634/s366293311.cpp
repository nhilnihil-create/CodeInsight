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
#define int long long
typedef pair<int, int> P;
vector<P> G[100010];

int d[100010];

void dfs(int x, int p = -1, int c = 0) {
    d[x] = c;
    for(auto to: G[x]) {
        if(to.first == p) continue;
        dfs(to.first, x, c + to.second);
    }
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    dfs(K);
    while(Q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << d[x] + d[y] << endl;
    }


    return 0;
}
