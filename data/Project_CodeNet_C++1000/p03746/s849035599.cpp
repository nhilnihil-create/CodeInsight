// #pragma GCC target("avx2")
#pragma GCC optimize("O3", "unroll-loops")
 
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
// template <typename T>
// using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = priority_queue<T>;
 
// #define X first
// #define Y second
#define ALL(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back
 
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RANDOM() random_device __rd; \
                 mt19937 __gen = mt19937(__rd()); \
                 uniform_int_distribution<int> __dis(0, 1); \
                 auto rnd = bind(__dis, __gen);
 
const int INF = 1E18;
const int mod = 1E9 + 7;
const int maxn = 1E5 + 5;

vector<int> adj[maxn], vis(maxn, 0);
deque<int> deck;

void dfs(int now, int root) {
    vis[now] = 1;
    for (auto x : adj[now]) {
        if (!vis[x]) {
            vis[x] = 1;
            
            if (root == -1) deck.push_front(x);
            else deck.push_back(x);
            
            dfs(x, root);
            
            if (now != root) return;
            else root = -1;
        }
    }
}

int32_t main() {
    fastIO();
    
    int n, m, u, v;
    cin >> n >> m;
    
    while (m--) cin >> u >> v, adj[u].eb(v), adj[v].eb(u);
    
    deck.push_back(1), dfs(1, 1);
    
    cout << deck.size() << "\n";
    while (!deck.empty()) {cout << deck.front() << " "; deck.pop_front();}
    
    return 0;
}