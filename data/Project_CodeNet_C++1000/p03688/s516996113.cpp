#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];

bool Check(int c)
{
    int un = 0, notun = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == c) notun++;
        else un++;
    if (un > c) return false;
    int lft = c - un;
    if (notun == 0) return lft == 0;
    if (lft == 0) return false;
    return notun >= 2 * lft;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    if (a[n - 1] - a[0] > 1) { printf("No\n"); return 0; }
    if (Check(a[n - 1])) { printf("Yes\n"); return 0; }
    if (a[0] == a[n - 1] && Check(a[0] + 1)) { printf("Yes\n"); return 0; }
    printf("No\n");
    return 0;
}
