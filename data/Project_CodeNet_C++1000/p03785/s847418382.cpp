/*
Author: Xjrjyy
LANG: C++
PROG: agc011_a.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAXN (100000 + 5)

int n, c, k;
int t[MAXN * 2];
int ans;

int main()
{
    scanf("%d%d%d", &n, &c, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t[i]);
    }
    std::sort(t, t + n);
    for (int i = 0, j = 0; i < n; i = j)
    {
        for (; j < i + c && t[j] <= t[i] + k; ++j);
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
