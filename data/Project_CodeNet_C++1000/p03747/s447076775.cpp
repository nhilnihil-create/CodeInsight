#include <bits/stdc++.h>
using namespace std;
int read();
int n, L, T;
int M(int x) { return x >= L ? x - L : x; }
int x[200005], dire[200005], q[2];
int res[200005];
vector<int> p[2];

int tmp;
int to(int a) {
    int rt = M((x[a] + (dire[a] ? 1 : -1) * T) % L + L);
    rt += L - tmp;
    return rt > L ? rt - L : rt;
}

bool cmp(int a, int b) { return b == 1 ? 0 : (a > b || a == 1); }

int dis(int a, int b) { return M((x[b] - x[a]) * (dire[a] ? 1 : -1) + L); }

int pre[2][200005];

long long calc(int i, int j) {
    return 1ll * pre[i][q[i] - 1] * (j / q[i]) +
           (j % q[i] ? pre[i][j % q[i] - 1] : 0);
}

int solve() {
    int t;
    if (!p[1].size() || (t = 2 * T - dis(1, p[1][0])) <= 0) return 1;
    for (int i = 0; i < 2; ++i) {
        if ((q[i] = p[i].size()) == 1) {
            pre[i][0] = L;
            continue;
        }
        for (int j = 0; j < q[i] - 1; ++j)
            pre[i][j] = dis(p[i][j + 1], p[i][j]);
        pre[i][q[i] - 1] = dis(p[i][0], p[i][q[i] - 1]);
        for (int j = 0; j < q[i]; ++j) pre[i][j] += pre[i][j - 1];
    }
    int l = 0, r = 1000000000, rs = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        long long len = calc(0, (mid >> 1) + (mid & 1)) + calc(1, mid >> 1);
        if (len <= t)
            l = mid + 1, rs = mid;
        else
            r = mid - 1;
    }
    rs = (rs & 1) ? p[0][((rs >> 1) + 1) % q[0]] : p[1][(rs >> 1) % q[1]];
    return rs;
}

int main() {
    n = read(), L = read(), T = read();
    for (int i = 1; i <= n; ++i)
        x[i] = read(), dire[i] = read() & 1, p[dire[i] ^ dire[1]].push_back(i);
    if (dire[1])
        sort(p[0].begin(), p[0].end(), cmp), sort(p[1].begin(), p[1].end());
    else
        sort(p[0].begin(), p[0].end()), sort(p[1].begin(), p[1].end(), cmp);
    int st = solve();
    tmp = to(st);
    for (int i = 1; i <= n; ++i) res[i] = to(i);
    res[st] = 0, sort(res + 1, res + 1 + n);
    for (int i = 1; i <= n; ++i) printf("%d\n", M(res[i] + tmp));
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
