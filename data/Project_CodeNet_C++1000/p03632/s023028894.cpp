#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int count = 0;
    for (int i = c; i < d; i++)
    {
        for (int j = a; j < b; j++)
        {
            if(i == j) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}