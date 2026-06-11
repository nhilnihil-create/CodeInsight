/*
Author: Xjrjyy
LANG: C++
PROG: agc010_a.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>

#define MAXN ()

int n, a, sum;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        sum = sum ^ (a & 1);
    }
    printf("%s", sum ? "NO" : "YES");
    return 0;
}
