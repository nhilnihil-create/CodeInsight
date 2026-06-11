#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> dist;
vector< vector<int> > G;

void dfs(int p, int s, int d)
{
    dist[s] = d;
    for(int t : G[s]) {
        if(t != p) dfs(s, t, d + 1);
    }
}

int main() {
    cin >> N >> K;
    dist.resize(N);
    G.resize(N);
    vector<pair<int,int>> E(N-1);
    for(int i=0; i<N-1; ++i) {
        cin >> E[i].first >> E[i].second;
        --E[i].first;
        --E[i].second;
        G[E[i].first].push_back(E[i].second);
        G[E[i].second].push_back(E[i].first);
    }

    int res = 1001001001;
    if(K % 2 == 0) {
        for(int s=0; s<N; ++s) {
            dfs(-1, s, 0);
            int cnt = 0;
            for(int i=0; i<N; ++i) {
                if(dist[i] > (K / 2)) ++cnt;
            }
            res = min(res, cnt);
        }
    } else {
        for(int i=0; i<N-1; ++i) {
            dfs(E[i].second, E[i].first, 0);
            dfs(E[i].first, E[i].second, 0);
            int cnt = 0;
            for(int i=0; i<N; ++i) {
                if(dist[i] > ((K - 1) / 2)) ++cnt;
            }
            res = min(res, cnt);
        }
    }
    cout << res << endl;
}