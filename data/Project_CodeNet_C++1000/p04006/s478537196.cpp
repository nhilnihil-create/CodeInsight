#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int a[2050]= {0};
const long long int inf=0x3f3f3f3f3f3f3f3f;
long long int b[2050][2050]= {0};
long long int n,x;
long long zz=inf;
int main()
{
    scanf("%lld%lld",&n,&x);
    for(long long int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    for(long long int i=1; i<=n; i++)
    {
        b[i][0]=a[i];
        for(long long int j=1; j<n; j++)
        {
            long long int cz=i-j;
            if(cz<=0)
                cz+=n;
            b[i][j]=min(b[i][j-1],a[cz]);
        }
    }
    for(long long int i=0; i<n; i++)
    {
        long long sum=x*i;
        for(long long int j=1; j<=n; j++)
            sum+=b[j][i];
        zz=min(zz,sum);
    }
    printf("%lld",zz);
    return 0;
}
