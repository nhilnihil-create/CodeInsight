#include<bits/stdc++.h>
using namespace std;

long long a[305][305],b[305][305],sum;
bool vis[305][305];
int n;

void FW1()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                b[i][j] = min(b[i][j],(b[i][k]+b[k][j]));
            }
        }
    }
    return;
}

void FW2()
{
    sum = 0;
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                long long x = a[i][j];
                long long y = a[i][k]+a[k][j];
                if(k!=i && k!=j && y==x)    vis[i][j] = vis[j][i] = true;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(!vis[i][j])  sum += a[i][j];
        }
    }
    sum /= 2;
    return;
}

long long check()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(b[i][j]!=a[i][j])    return  -1;
        }
    }
    FW2();
    return  sum;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%lld",&a[i][j]);
            b[i][j] = a[i][j];
        }
    }
    FW1();
    printf("%lld\n",check());
    return  0;
}
