#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int a[200500]={0};
long long int l[200500]={0};
long long int r[200500]={0};
int main()
{
    register int n;
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(register int i=1;i<=n;i++)
    {
        for(l[i]=i;l[i]>1;)
        {
            if(a[l[i]-1]>a[i])
                l[i]=l[l[i]-1];
            else
                break;
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(r[i]=i;r[i]<=n;)
        {
            if(a[r[i]+1]>a[i])
            {
                r[i]=r[r[i]+1];
            }
            else
                break;
        }
    }
    register long long int sum=0;
    for(register int i=1;i<=n;i++)
    {
        sum+=a[i]*(i-l[i]+1)*(r[i]-i+1);
    }
    printf("%lld",sum);
    return 0;
}
