#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<P>> vv;

const ll INF = 1e15;

// input
int N;
vector<int> A, B, C;
int Q, K;
vector<int> X, Y;

vv link;
vector<bool> vis;
vector<ll> w;


void input() {
    cin >> N;
    A = B = C = vector<int>(N - 1);
    rep(i, N - 1) cin >> A[i] >> B[i] >> C[i];
    cin >> Q >> K;
    X = Y = vector<int>(Q);
    rep(i, Q) cin >> X[i] >> Y[i];
}


void dfs(int u) {
    vis[u] = true;
    for (P x : link[u]) {
        if (vis[x.first]) continue;
        w[x.first] = w[u] + x.second;
        dfs(x.first);
    }
}


int main() {
    input();
    link = vv(N);
    rep(i, N - 1) {
        int a = A[i] - 1;
        int b = B[i] - 1;
        int c = C[i];
        link[a].push_back(P(b, c));
        link[b].push_back(P(a, c));
    }
    vis = vector<bool>(N, false);
    w = vector<ll>(N, INF);
    w[K - 1] = 0;
    dfs(K - 1);
    rep(i, Q) {
        ll ans = w[X[i] - 1] + w[Y[i] - 1];
        cout << ans << endl;
    }
}
