#include <bits/stdc++.h>
using namespace std;

template<class T> inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

long long n, a[2000005], stk[2000005], r[2000005], l[2000005];
long long ans, top;

inline void init() {
    read(n);
    for (int i = 1; i <= n; ++i)
        read(a[i]), r[i] = n + 1, l[i] = 0;
    return;
}

inline void solve() {
    for (int i = 1; i <= n; ++i) {
        while (top && a[stk[top]] > a[i])
            r[stk[top]] = i, top--;
        l[i] = stk[top];
        stk[++top] = i;
    }
    for (int i = 1; i <= n; ++i)
        ans += (r[i] - i) * (i - l[i]) * a[i];
    cout << ans << endl;
    return;
}

int main() {
    init();
    solve();
    return 0;
}