#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

using namespace std;

int main() {

    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    REP(_, M) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        g[A].push_back(B);
        g[B].push_back(A);
    }

    vector<bool> used(N, false);
    vector<vector<int>> path(2); 
    path[0].push_back(0);
    path[1].push_back(g[0][0]);
    used[0] = true;
    used[g[0][0]] = true;

    function<void(int, int)> f = [&](int u, int path_id) {
        bool updated = true;
        while (updated) {
            updated = false;
            for (int v: g[u]) {
                if (!used[v]) {
                    used[v] = true;
                    path[path_id].push_back(v);
                    u = v;
                    updated = true;
                    break;
                }
            }
        }
    };
    
    f(0, 0);
    f(g[0][0], 1);

    cout << (path[0].size() + path[1].size()) << endl;
    RREP(i, path[0].size()) cout << (path[0][i] + 1) << " "; // 1-based indexing
    REP(i, path[1].size()) cout << (path[1][i] + 1) << " "; // 1-based indexing
    cout << endl;

    return 0;
}
