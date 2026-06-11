#include <bits/stdc++.h>                        
#define pb push_back                            
#define mp make_pair                            
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define jonathan ios_base::sync_with_stdio(0)
#define livingston cin.tie(0)
using namespace std;                            
                                                
void yes() {cout << "YES" << endl;}                                               
void no() {cout << "NO" << endl;}                                                        
                                                
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};         
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1}; 

const int INF = 1e9 + 9;
const long long LINF = 1e18 + 8;
const double EPS = 1e-9;
const long long MOD = 998244353;
const double PI = acos(-1);

vector<int> g[2020];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int res = n;
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        vector<int> d(n + 1, INF);
        d[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < sz(g[v]); i++) {
                int to = g[v][i];
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] > k / 2) cnt++;
        }
        res = min(res, cnt);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz(g[i]); j++) {
            int u = i, v = g[i][j];
            queue<int> q;
            vector<int> d(n + 1, INF);
            d[u] = 0; d[v] = 0;
            q.push(u); q.push(v);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i = 0; i < sz(g[v]); i++) {
                    int to = g[v][i];
                    if (d[to] > d[v] + 1) {
                        d[to] = d[v] + 1;
                        q.push(to);
                    }
                }
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (d[i] > (k - 1) / 2) cnt++;
            }
            res = min(res, cnt);
        }
    }
    cout << res << endl;
} 

int main() {
    jonathan; 
    livingston;
    solve();
    return 0;
}