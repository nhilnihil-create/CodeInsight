#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 6;
const ll LLINF = 4e18;

void print_dfs(const vector<vector<int>> &G, int n, int p = -1) {
    cout << n + 1 << " " << endl;
    REP(i, G[n].size()) {
        if (G[n][i] != p) print_dfs(G, G[n][i], n);
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n), outG(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(n, false);
    stack<pair<int,int>> sta;
    int count = 0;
    sta.push({0,-1});
    while (!sta.empty()) {
        pair<int,int> p = sta.top(); sta.pop();
        if (visited[p.first]) continue;
        count++;
        visited[p.first] = true;
        if (p.second != -1) {
            outG[p.first].push_back(p.second);
            outG[p.second].push_back(p.first);
            for (int v : G[p.first]) {
                if (!visited[v]) {
                    sta.push({v,p.first});
                    break;
                }
            }
        }
        else {
            int c = 0;
            for (int v : G[p.first]) {
                if (!visited[v]) {
                    sta.push({v,p.first});
                    if (c == 1) break;
                    c++;
                }
            }
        }
    }
    int root;
    REP(i, n) {
        if (outG[i].size() == 1) {
            root = i;
            break;
        }
    }
    /*REP(i, n) {
        cout << i << " -> ";
        REP(j, outG[i].size()) {
            cout << outG[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << count << endl;
    print_dfs(outG,root);
    getchar(); getchar();
}