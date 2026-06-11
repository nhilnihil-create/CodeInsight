#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int a[25000]={0};
long long int b[25000]={0};
int p[25000]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+n+10;
    }
    for(int i=n;i>=0;i--)
    {
        b[i]=b[i+1]+n+10;
    }
    long long syg=0;
    for(int i=1;i<=n;i++)
    {
        a[p[i]]+=i;
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%lld ",b[i]);
    return 0;
}
