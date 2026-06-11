#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

/*
#define cin ifs
#define cout ofs
ifstream ifs("in.txt");
ofstream ofs("out.txt");
//*/

int N, M;
vector<int> G[100000];
int color[100000] = {};
vector<bool> bipartite;
vector<int> npoints;

bool dfs(int n, int c) {
    color[n] = c;
    npoints[npoints.size() - 1]++;
    bool res = true;
    for (int i = 0; i < G[n].size(); i++) {
        if (color[G[n][i]] == c) {
            res = false;
        } else if (color[G[n][i]] == 0) {
            res &= dfs(G[n][i], -c);
        }
    }
    return res;
}

signed main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < N; i++) {
        if (color[i] == 0) {
            npoints.push_back(0);
            bipartite.push_back(dfs(i, 1));
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < npoints.size(); i++) {
        if (npoints[i] == 1) {
            a++;
        } else if (!bipartite[i]) {
            b++;
        } else {
            c++;
        }
    }
    int ans = 2 * a * N - a * a + b * b + 2 * b * c + 2 * c * c;
    cout << ans << endl;

    return 0;
}