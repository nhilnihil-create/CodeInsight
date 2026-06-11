#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
int n, m;
vector <int> g[N];
bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }
    vector <int> ans = {1};
    used[1] = 1;
    while (1) {
        int u = ans.back();
        for (int v : g[u]) {
            if (!used[v]) {
                ans.app(v);
                used[v] = 1;
                break;
            }
        }   
        if (ans.back() == u)
            break;
    }   
    reverse(all(ans));
    while (1) {
        int u = ans.back();
        for (int v : g[u]) {
            if (!used[v]) {
                ans.app(v);
                used[v] = 1;
                break;
            }
        }   
        if (ans.back() == u)
            break;
    }   
    cout << ans.size() << endl;
    for (int e : ans)
        cout << e << ' ';
    cout << endl;            
}