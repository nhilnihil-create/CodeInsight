#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
int n, sg[N];
vector<int> nxt[N];

void dfs(int x, int fa) {
    for (int i = 0; i < nxt[x].size(); i++) {
        int y = nxt[x][i];
        if (y == fa) continue;
        dfs(y, x);
        sg[x] ^= (sg[y] + 1);
    }
}

int main() {
    cin >> n;
    rep(i, 1, n - 1) {
        int x, y; scanf("%d%d", &x, &y);
        nxt[x].push_back(y), nxt[y].push_back(x);
    }
    dfs(1, 0);
    puts(sg[1] ? "Alice" : "Bob");
    return 0;
}
