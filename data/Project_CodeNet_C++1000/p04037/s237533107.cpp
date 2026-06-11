#include<bits/stdc++.h>

const int N = 1e5 + 10;

int n, a[N];

inline int read() {
    int x = 0, k = 1; char c = getchar();
    for (; c < 48 || c > 57; c = getchar()) k ^= (c == '-');
    for (; c >= 48 && c <= 57; c = getchar()) x = x * 10 + (c ^ 48);
    return k ? x : -x;
}

inline bool cmp(int x, int y) {
    return x > y;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n, cmp);
    
    int t = 1;
    for (; t < n && t < a[t + 1]; t++);
    int w = n + 1;
    for (; w > 1 && a[w - 1] < t; w--);
    w = w - 1;
    if ((a[t] - t) % 2 == 1 || ((w >= t) && (a[w] >= t) && (w - t) % 2 == 1))
        puts("First");
    else
        puts("Second");
    return 0;
}