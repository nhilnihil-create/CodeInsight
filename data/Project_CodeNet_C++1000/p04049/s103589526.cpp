#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MAX_N = 2000 + 5;

struct Node {
    LL id;
    Node *nex;
    Node(LL id_ = 0, Node *nex_ = NULL)
        : id(id_), nex(nex_) {}
} *head[MAX_N];

void init() {
    for (LL i = 0; i < MAX_N; ++i) head[i] = new Node(-1, NULL);
}

void addEdge(LL u, LL v) {
    Node *e = new Node(v, head[u]->nex); head[u]->nex = e;
    Node *r = new Node(u, head[v]->nex); head[v]->nex = r;
}

LL n, k, A[MAX_N], B[MAX_N];

stack <LL> stk, path;
LL firPath = -1, firNode = -1;
void dfs(LL u, LL fa, LL step, bool recPath) {
    if (recPath) stk.push(u);
    bool haveSon = false;
    for (Node *it = head[u]->nex; it != NULL; it = it->nex) {
        if (it->id != fa) {
            haveSon = true;
            dfs(it->id, u, step + 1, recPath);
        }
    }
    if (step > firPath) {
        firNode = u; firPath = step;
        if (!haveSon) path = stk;
    }
    if (recPath) stk.pop();
}

LL cal(LL u, LL fa, LL step) {
    LL ret = 0;
    if (step > k / 2) ++ret;
    for (Node *it = head[u]->nex; it != NULL; it = it->nex) {
        if (it->id != fa) {
            ret += cal(it->id, u, step + 1);
        }
    }
    // printf("Call cal(u = %lld, fa = %lld, step = %lld), ", u, fa, step);
    // printf("return (ret = %lld)\n", ret);
    return ret;
}

int main() {
    scanf("%lld%lld", &n, &k);
    LL u, v;
    init();
    for (LL i = 1; i <= n - 1; ++i) {
        scanf("%lld%lld", &u, &v);
        addEdge(u, v);
        A[i] = u; B[i] = v;
    }
    LL ans = INT_MAX;
    if (k % 2 == 0) {
        for (LL i = 1; i <= n; ++i) ans = min(ans, cal(i, -1, 0));
    } else {
        for (LL i = 1; i <= n - 1; ++i) ans = min(ans, cal(A[i], B[i], 0) + cal(B[i], A[i], 0));
    }
    printf("%lld\n", ans);
    return 0;
}