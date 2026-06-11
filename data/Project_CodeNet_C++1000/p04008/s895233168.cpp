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

int n, k;
int p[N];
int ans = 0;
vector <int> tree[N];
int h[N];
void dfs(int u) {
    for (int v : tree[u]) {
        dfs(v);
        if (h[v] >= k - 1 && u != 1) {
            ++ans;
        }   
        else {
            h[u] = max(h[u], h[v] + 1);
        }   
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }   
    ans += p[1] != 1;
    p[1] = 1;
    for (int i = 2; i <= n; ++i) {
        tree[p[i]].app(i);
    }   
    dfs(1);
    cout << ans << endl;
}