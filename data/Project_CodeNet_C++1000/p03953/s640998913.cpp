#include <bits/stdc++.h>
#define reg register
using namespace std;

typedef long long ll;
const int maxn = 100005;

inline ll read() {
    reg ll s = 0, t = 0; reg char ch = getchar();
    while (!isdigit(ch)) t |= ch == '-', ch = getchar();
    while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}

int n, m, a[maxn], d[maxn], x[maxn], pos[maxn], Stack[maxn], top;
ll k, ans[maxn];
bool used[maxn];

int main() {
    ios::sync_with_stdio(false);
    n = read();
    for (reg int i = 1; i <= n; i++) x[i] = read();
    for (reg int i = 1; i <= n; i++) d[i] = x[i] - x[i - 1];
    m = read(), k = read();
    for (reg int i = 1; i <= m; i++) a[i] = read();
    for (reg int i = 1; i <= n; i++) pos[i] = i;
    for (reg int i = 1; i <= m; i++) swap(pos[a[i]], pos[a[i] + 1]);
    for (reg int i = 1; i <= n; i++)
        if (!used[i]) {
            top = 0;
            for (reg int j = i; !used[j]; j = pos[j]) Stack[++top] = j, used[j] = true;
            for (reg int j = 1; j <= top; j++)
                ans[Stack[j]] = d[Stack[(k + j - 1) % top + 1]];
        }
    for (reg int i = 1; i <= n; i++) ans[i] += ans[i - 1], printf("%lld\n", ans[i]);
    return 0;
}
