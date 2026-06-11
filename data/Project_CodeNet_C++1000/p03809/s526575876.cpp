#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define REP(i,n) for (int i = 0; i < n; ++i)
#define FORE(x,xs) for (auto &x : xs)
const int MAX = 1e5+10;

int N;
int A[MAX];
vi edge[MAX];
int parent[MAX];

void makeTree(int n, int p) {
    parent[n] = p;
    FORE (v, edge[n]) {
        if (v == p) continue;
        makeTree(v, n);
    }
}

ll dfs(int n) {
    ll s = 0, mx = 0;
    if (edge[n].size() == 1) return A[n];
    FORE (e, edge[n]) {
        if (parent[e] != n) continue;
        ll m = dfs(e);
        mx = max(mx, m);
        if (m == -1) return -1;
        s += m;
    }
    ll r = 2 * A[n] - s;
    if (r < 0 || r > A[n] || s - mx < (s-r)/2) r = -1;
    return r;
}

int main() {
    cin >> N;
    REP (i, N) cin >> A[i];
    REP (i, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    if (N == 2) {
        string ans = (A[0] == A[1]) ? "YES" : "NO";
        cout << ans << endl;
        return 0;
    }

    int root = 0;
    REP (i, N) {
        if (edge[i].size() >= 2) { root = i; break; }
    }

    makeTree(root, -1);
    string ans = "NO";
    if (dfs(root) == 0) ans = "YES";
    cout << ans << endl;
}