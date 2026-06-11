#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;

bool dfs(const vector<vector<int> >& e, int node, int target, vector<int>& visited, int depth) {
    visited[node] = 1;
    if (target == node) {
        return true;
    }

    depth++;
    if (depth > 2) {
        return false;
    }

    auto& c = e[node];
    rep(i, c.size()) {
        if (visited[c[i]] <= 0) {
            if (dfs(e, c[i], target, visited, depth)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    
    vector<vector<int> > e(n + 1, vector<int>());
    rep(i, m) {
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }

    vector<int> visited(n + 1);
    if (dfs(e, 1, n, visited, 0)) {
        put("POSSIBLE")
    }
    else {
        put("IMPOSSIBLE")

    }


    return 0;
}