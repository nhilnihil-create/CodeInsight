#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int n,m,a[maxn],cnt,a1,a2;

bool cmp(int x,int y)
{
    if (x % 2 == 1 && y % 2 == 0)
        return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] % 2 == 1)
            cnt++;
    }
    if (cnt > 2)
    {
        puts("Impossible");
        return 0;
    }
    sort(a + 1,a + 1 + m,cmp);
    if (a[2] % 2 == 1)
        swap(a[2],a[m]);
    for (int i = 1; i <= m; i++)
        printf("%d ",a[i]);
    printf("\n");
    if (m == 1)
    {
        if (a[1] != 1)
        {
            printf("%d\n",2);
            printf("%d %d\n",a[1] - 1,1);
        }
        else
        {
            printf("%d\n",1);
            printf("%d\n",1);
        }
    }
    else
    {
        if (a[1] != 1)
        {
            printf("%d\n",m);
            printf("%d ",a[1] - 1);
            for (int i = 2; i < m; i++)
                printf("%d ",a[i]);
            printf("%d\n",a[m] + 1);
        }
        else
        {
            if (m != 2)
            {
                printf("%d\n",m - 1);
                printf("%d ",a[2]);
                for (int i = 3; i < m; i++)
                    printf("%d ",a[i]);
                printf("%d\n",a[m] + 1);
            }
            else
            {
                printf("%d\n",1);
                printf("%d\n",a[2] + 1);
            }
        }
    }

    return 0;
}
