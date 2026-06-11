/*
Author: Xjrjyy
LANG: C++
PROG: agc009_a.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXN (100005 * 3)

int n;
int a[MAXN];
long long ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * 3; ++i)
    {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n * 3);
    for (int i = 1; i <= n; ++i)
    {
        ans += a[n * 3 - i * 2];
    }
    printf("%lld\n", ans);
    return 0;
}
