#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int n, k, x, len[N], ans = 0;
vector<int> v[N];
void dfs(int x, int fx) {
    for (auto y : v[x]) {
        dfs(y, x);
        len[x] = max(len[x], len[y]);
    }
    len[x]++;
    if (fx != 1 && x != 1 && len[x] == k) ans++, len[x] = 0;
}
int main() {
    scanf("%d%d%d", &n, &k, &x);
    if (x != 1) ans++;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        v[x].push_back(i);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}