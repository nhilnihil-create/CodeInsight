#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, a[1000], i, j, m, hol=0, x[2], y[2], t=0, c;
    scanf("%d %d", &n, &m);
    for(i=1;i<=m;i++)
    {
        scanf("%d", &a[i]);
        if(a[i]%2)
        {
            hol++;
            if(hol==1)
            {
                x[0]=i;
                x[1]=a[i];
            }
            else if(hol==2)
            {
                y[0]=i;
                y[1]=a[i];
            }
        }
            
        }
    if(hol>=3)
        printf("Impossible");
    else
    {
        if(hol>=1)
            {
                c=a[1];
                a[1]=a[x[0]];
                a[x[0]]=c;
            }
        if(hol==2)
        {
            c=a[y[0]];
            a[y[0]]=a[m];
            a[m]=c;
        }
        for(i=1;i<=m;i++)
            printf("%d ", a[i]);
        printf("\n");
        if(m==1)
        {
            if(n==1)
                {
                    printf("%d\n%d", 1, 1);
                    
                }
                else
                {
            printf("%d\n", 2);
            printf("%d %d", 1, n-1);
                }
        }
        else
        {
        t+=(a[1]==1)+(a[m]==1);
        printf("%d\n", m+1-t);
        if(a[1]==1)
        {
            a[1]=2;
            if(a[m]==1)
            {
                for(i=1;i<=m-1;i++)
                    printf("%d ", a[i]);
            }
            else
            {
                a[m]-=1;
                for(i=1;i<=m;i++)
                    printf("%d ", a[i]);
            }
        }
        else
        {
            printf("%d %d ", a[1]-1, 2);
            if(a[m]==1)
            {
                for(i=2;i<=m-1;i++)
                    printf("%d ", a[i]);
            }
            else
            {
                a[m]-=1;
                for(i=2;i<=m;i++)
                    printf("%d ", a[i]);
            }
        }
        }
    }
    return 0;
}