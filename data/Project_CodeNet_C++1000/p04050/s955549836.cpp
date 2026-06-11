// Crt. 2020-01-13  08:35:28
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100005
using namespace std;

int n, m, a[N], b[N], cnt;

inline bool cmp(int x, int y) {
    return x % 2 > y % 2;
}

int main() {
#ifdef LOCAL_JUDGE
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        scanf("%d", a + i);

    if (m == 1) {
        if (a[1] == 1) cout << 1 << endl << 1 << endl << 1 << endl;
        else cout << a[1] << endl << 2 << endl << max(1, a[1] - 1) << " " << 1 << endl;
        return 0;
    }

    if (m == 2) {
        if (a[1] > a[2]) swap(a[1], a[2]);
        if (a[2] == 1) cout << a[1] << " " << a[2] << endl << 1 << endl << 2 << endl;
        else cout << a[1] << " " << a[2] << " " << endl << 2 << endl << a[1] + 1 << " " << a[2] - 1 << endl;
        return 0;
    }

    sort(a + 1, a + m + 1, cmp);

    int pos = 0;
    while (pos < m && a[pos + 1] % 2) ++pos;

    if (pos > 2) return puts("Impossible"), 0;

    if (pos == 2) swap(a[pos], a[m]);

    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i]);
    puts("");

    if (a[1] == 1) b[++cnt] = a[2];
    else b[++cnt] = a[1] - 1, b[++cnt] = a[2];

    for (int i = 3; i < m; ++i)
        b[++cnt] = a[i];

    b[++cnt] = a[m] + 1;

    cout <<cnt << endl;
    for (int i = 1; i <= cnt; ++i)
        printf("%d ", b[i]);

	return 0;
}
