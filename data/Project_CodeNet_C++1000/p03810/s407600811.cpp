#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n,tot;
LL a[100010];
LL gcd(LL x,LL y)
{
    if (x%y == 0) return y;
    else return gcd(y,x%y);
}
int init()
{
    for (int i = 0;i < n;i++) if (a[i]&1)
    {
        if (a[i] == 1) return 0;
        else a[i]--;
    }
    LL g = a[0];
    for (int i = 1;i < n;i++) g = gcd(g,a[i]);
    for (int i = 0;i < n;i++) a[i] /= g;
    tot = 0;
    for (int i = 0;i < n;i++) if (!(a[i]&1)) tot++;
    return 1;
}
int dfs()
{
    if (tot&1) return 1;
    else {
        if (n-tot >= 2) return 0;
        else {
            if (!init()) return 0;
            return dfs()^1;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        scanf("%lld",&a[i]);
        if (!(a[i]&1)) tot++;
    }
    if (dfs()) printf("First\n");
    else printf("Second\n");
    return 0;
}
