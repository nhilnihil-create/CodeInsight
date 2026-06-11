#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int) (x).size())
typedef long long ll;

const int N = 123456;

int n;
vector<int> e[N];

ll grundy(int u, int p = -1) {
    ll g = 0;
    for (int v: e[u]) {
        if (v == p) continue;
        g ^= grundy(v, u);
    }
    return g + (p != -1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    ll g = grundy(1);
    puts(g ? "Alice" : "Bob");
}
