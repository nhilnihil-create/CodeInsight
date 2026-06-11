/*
Author: Xjrjyy
LANG: C++
PROG: agc003_b.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>

#define MAXN (100005)

int n;
int s[MAXN];
long long ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (s[i] & 1 && s[i + 1])
        {
            ++s[i];
            --s[i + 1];
        }
        ans += s[i] >> 1;
    }
    printf("%lld", ans);
    return 0;
}
