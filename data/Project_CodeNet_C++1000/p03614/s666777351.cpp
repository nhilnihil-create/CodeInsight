#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, M[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a == i)
            M[i] = 1;
    }
    int r = 1, tot = 0;
    for (int i = 1; i <= n; i++)
        if (M[i])
        {
            r = i;
            while (M[r])
                r ++;
            tot += (r - i + 1) >> 1;
            i = r;
        }
    return !printf("%d\n", tot);
}