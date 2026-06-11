#include<bits/stdc++.h>
#define fo(i, a, b) for (int i = (a); i <= (b); ++i)
#define fd(i, a, b) for (int i = (a); i >= (b); --i)
#define edge(i, u) for (int i = head[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define mod 1000000007
#define ll long long
#define N 205
#define pb push_back
int n, m, a[N], cnt, x, y;
int main ()
{
    scanf("%d %d", &n, &m);
    fo (i, 1, m)
        scanf("%d", &a[i]);
    if (m == 1)
    {
        printf("%d\n", a[1]);
        if (n > 1)
            printf("2\n%d %d", n - 1, 1);
        else
            printf("1\n1");
    }
    else
    {
        fo (i, 1, m)
            if (a[i] & 1) ++cnt;
        if (cnt >= 3)
        {
            printf("Impossible");
        }
        else
        {
            fo (i, 1, m)
            {
                if (a[i] & 1)
                {
                    if (!x)
                        x = i;
                    else
                        y = i;
                }
            }
            if (x)
                std::swap(a[1], a[x]);
            if (y)
                std::swap(a[m], a[y]);
            fo (i, 1, m) printf("%d ", a[i]);
            printf("\n");
            a[1]--; a[m]++;
            int l = 1;
            if (!a[l]) ++l;
            printf("%d\n", m - l + 1);
            fo (i, l, m)
                printf("%d ", a[i]);
        }
    }
}