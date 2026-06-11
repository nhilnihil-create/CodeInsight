#include <bits/stdc++.h>
using namespace std;
int read();
int n, a[100005];

bool cmp(int x, int y) { return x > y; }

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
        if (i + 1 > a[i + 1]) {
            int b = (a[i] - i) & 1;
            if (!b)
                for (int j = i + 1; a[j] == i; ++j) b ^= 1;
            return puts(b ? "First" : "Second"), 0;
        }
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
