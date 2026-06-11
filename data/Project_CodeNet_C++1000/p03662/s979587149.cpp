#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

void solve() {
    int N, a, b;
    cin >> N;
    vector<int> edge[N];
    rep(i, N - 1) {
        cin >> a >> b;
        edge[a - 1].push_back(b - 1);
        edge[b - 1].push_back(a - 1);
    }
    int d[2][N];
    rep(i, 2) rep(j, N) d[i][j] = -1;
    rep(i, 2) {
        d[i][i * (N - 1)] = 0;
        deque<int> q{i * (N - 1)};
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            rep(j, edge[u].size()) {
                int v = edge[u][j];
                if (d[i][v] > -1) continue;
                d[i][v] = d[i][u] + 1;
                q.push_back(v);
            }
        }
    }
    int S = 0, F = 0;
    rep(i, N) {
        if (d[0][i] > d[1][i]) S++;
        else F++;
    }
    if (F > S) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return;
}

int main() {
    solve();
}