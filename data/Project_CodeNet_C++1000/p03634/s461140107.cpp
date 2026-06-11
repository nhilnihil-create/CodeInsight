#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int INF = 1001001001;
vector<P> to[100005];
vector<ll> dist(100005);

void dfs(int k, int d, ll r){
    dist[k] = r;
    int x = to[k].size();
    for (int i = 0; i < x; i++){
        if(to[k][i].first == d)continue;
        int nex = to[k][i].first;
        ll omomi = to[k][i].second;
        dfs(nex, k, r+omomi);
    }

    return;
}

int main() {
    int N; cin >> N;

    rep(i, N-1){
        int a, b, c; cin >> a >> b >> c;
        a--;
        b--;
        to[a].push_back(make_pair(b, c));
        to[b].push_back(make_pair(a, c));
    }

    int Q, K; cin >> Q >> K;
    K--;
    dfs(K, -1, 0);

    rep(i, Q){
        int x, y; cin >> x >> y;
        x--;
        y--;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }


    return 0;
}