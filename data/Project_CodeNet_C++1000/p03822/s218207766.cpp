#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 1e5 + 7;
vector <int> tree[N];

int dfs(int u) {
    vector <int> ans;
    for (int v : tree[u]) {
        ans.app(dfs(v));
    }
    int mx = tree[u].size();
    sort(all(ans));
    reverse(all(ans));
    for (int i = 0; i < ans.size(); ++i)
        mx = max(mx, ans[i] + i + 1);
    #ifdef HOME
    cout << u << ' ' << mx << endl;
    #endif
    return mx;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        tree[p].app(i);
    }   
    cout << dfs(1) << endl;
}