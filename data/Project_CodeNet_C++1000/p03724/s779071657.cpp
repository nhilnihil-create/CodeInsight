#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n,m;
int z[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int tmp1,tmp2;
        scanf("%d%d", &tmp1, &tmp2);
        ++z[tmp1];
        ++z[tmp2];
    }
    int flag = 1;
    for (int i = 1; i <= n; ++i)
        if (z[i] % 2)
            flag = 0;
    if (flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}
