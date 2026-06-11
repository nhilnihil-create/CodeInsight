#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, a[MAXN], ans;
int pre[MAXN], suf[MAXN];

int read() {
    char c = getchar();
    int x = 0;
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c)) {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int solve() {
//    for (int i = 1; i <= n; ++i)
//        printf("%d ", a[i]);
//    cout << endl;
    int tempsuf[MAXN], temppre[MAXN];
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res ^= (a[i] - 1) & 1;
    if (res)
        return true;
    pre[1] = a[1];
    for (int i = 2; i <= n; ++i)
        pre[i] = gcd(pre[i - 1], a[i]);
    suf[n] = a[n];
    for (int i = n - 1; i >= 1; --i)
        suf[i] = gcd(suf[i + 1], a[i]);
    memcpy(temppre, pre, sizeof(pre));
    memcpy(tempsuf, suf, sizeof(suf));
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1)
            continue;
        int d;
        if (i == 1)
            d = gcd(a[i] - 1, suf[i + 1]);
        else if (i == n)
            d = gcd(a[i] - 1, pre[i - 1]);
        else
            d = gcd(gcd(suf[i + 1], pre[i - 1]), a[i] - 1);
        if (d != 1) {
            --a[i];
            for (int j = 1; j <= n; ++j)
                a[j] /= d;
            int res = solve();
            for (int j = 1; j <= n; ++j)
                a[j] *= d;
            ++a[i];
            memcpy(pre, temppre, sizeof(pre));
            memcpy(suf, tempsuf, sizeof(suf));
            if (!res)
                return true;
        }
    }
    return false;
}

int main() {
//    freopen("in11.txt", "r", stdin);
    n = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    int res = solve();
    puts(res ? "First" : "Second");
}
