#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORE(x,xs) for (auto x : xs)

const int MAX = 1e5+10;

int N;
vi child[MAX];

int dfs(int n) {
    if (child[n].size() == 0) return 0;
    vi sub;
    FORE (c, child[n]) {
        sub.push_back(dfs(c));
    }
    sort(sub.rbegin(), sub.rend());
    int mx = 0;
    FOR (i, 0, sub.size()) {
        mx = max(mx, sub[i] + i+1);
    }
    return mx;
}

int main() {
    cin >> N;
    FOR (i, 1, N) {
        int a;
        cin >> a;
        child[--a].push_back(i);
    }

    cout << dfs(0) << endl;
}