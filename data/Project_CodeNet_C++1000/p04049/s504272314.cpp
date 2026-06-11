#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 5;

struct edge {
    int v;
    edge *next;
} pool[N], *h[N];

int ans, top = -1;
int n, k;
vector <int> A, B;

inline void addedge(int u, int v) {
    edge *tmp = &pool[++top];
    tmp -> v = v; tmp -> next = h[u]; h[u] = tmp;
}

int dfs(int u, int pre, int len) {
    int res = 1;
    if(len == 0) return res;
    for(edge *tmp = h[u]; tmp != NULL; tmp = tmp -> next) {
        int v = tmp -> v;
        if(v == pre) continue;
        res += dfs(v, u, len - 1);
    }
    return res;
}

void init() {
    int x, y;
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
        A.push_back(x), B.push_back(y);
    }
    if(k % 2 == 0) {
        for(int u = 1; u <= n; u++) {
            ans = max(ans, dfs(u, 0, k / 2));
        }
    }
    else {
        for(int i = 0; i < A.size(); i++) {
            int u = A[i], v = B[i];
            ans = max(ans, dfs(u, v, k / 2) + dfs(v, u, k / 2));
        }
    }
    printf("%d\n", n - ans);
}

int main() {
    init();
    return 0;
}

//22:25:20