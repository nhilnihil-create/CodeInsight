#include <bits/stdc++.h>

const int N = 2e5 + 10;

int a[N];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x;
}

inline int check(int k, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[n + i] >  k && a[n + i + 1] >  k || a[n - i] >  k && a[n - i - 1] >  k) return 0;
        if (a[n + i] <= k && a[n + i + 1] <= k || a[n - i] <= k && a[n - i - 1] <= k) return 1;
    }
    return a[1] <= k;
}

int main()
{
    int n = read() * 2 - 1;
    for (int i = 1; i <= n; ++i) a[i] = read();
    int l = 1, r = n, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid, n + 1 >> 1)) res = mid, r = mid - 1; else l = mid + 1;
    }
    std::cout << res << std::endl;
    return 0;
}