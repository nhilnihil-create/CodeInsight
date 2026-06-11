#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100000

vector < int > g[MAXN + 1];
bool viz[MAXN + 1];

int dfs(int x) {
    int ans = 0;
    viz[x] = 1;
    for (auto &y : g[x])
        if (viz[y] == 0)
            ans ^= 1 + dfs(y);
    return ans;
}

int main() {
    int n;
    cin >> n;

    for (n--; n; n--) {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << ( dfs( 1 ) ? "Alice" : "Bob" );

    return 0;
}
