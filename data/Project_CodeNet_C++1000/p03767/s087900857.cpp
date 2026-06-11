#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,n,ans=0;
    scanf("%lld",&n);
    long long a[(3*n)];
    for(i=0;i<3*n;i++)
    {
        scanf("%lld",&a[i]);
    }

    sort(a,a+(3*n));
    for(i=0,j=(n*3)-2;i<n;i++,j-=2)
    {
        ans+=a[j];
    }
    printf("%lld",ans);

    return 0;
}