#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int read();

int N, x[200005], st[200005], a[200005];
int work() {
    int m = N / 2 + 1, res = a[m], l = m, r = m;
    a[0] = a[1], a[N + 1] = a[N];
    for (; l >= 1 && a[l] != a[l - 1] && a[r] != a[r + 1]; --l, ++r) res ^= 1;
    return res;
}

int main() {
 //   freopen("triangle.in", "r", stdin);
   // freopen("triangle.out", "w", stdout);
    N = read() * 2 - 1;
    for (int i = 1; i <= N; ++i) st[i] = x[i] = read();
    sort(st + 1, st + 1 + N);
    int l = 1, r = N, res = r;
    while (l <= r) {
        int mid = l + r >> 1;
        for (int i = 1; i <= N; ++i) a[i] = x[i] > st[mid];
        if (!work())
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", st[res]);
    return 0;
}
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) f = (c == '-') ? -1 : f, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}