#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector< vector<int> > &g, vector<int> &dist, int v, int p=-1, int d=0) {
    dist[v] = d;
    for(auto u: g[v]) {
        if(u == p) continue;
        dist[u] = dist[v] + 1;
        dfs(g, dist, u, v, d+1);
    }
    return;
}

int main(void) {
    int N;
    cin >> N;
    vector< vector<int> > g(N);
    for(int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    vector<int> distF(N), distS(N);
    dfs(g, distF, 0);
    dfs(g, distS, N-1);

    int F = 0, S = 0;
    for(int i=0; i<N; i++) {
        if(distF[i] <= distS[i]) {
            ++F;
        } else {
            ++S;
        }
    }

    if(F > S) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }
    return 0;
}
