#include<bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;

long long a[100100],b[100100];

main()
{
    long long n,m;
    long long suma=0;
    long long sumb=0;
    long long ans=0;
    scanf("%lld %lld",&n,&m);
    for(long long i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(long long i=0;i<m;i++)
        scanf("%lld",&b[i]);
    long long total=0;
    for(long long i=0;i<n;i++)
    {
        //printf("%lld\n",n*a[i]-suma);
        total+=(i)*a[i]-suma;
        total%=MOD;
        suma+=a[i];
        suma%=MOD;
    }
    long long total2=0;
    for(long long i=0;i<m;i++)
    {
        total2+=(i)*b[i]-sumb;
        total2%=MOD;
        sumb+=b[i];
        sumb%=MOD;
    }
    printf("%lld\n",(total*total2)%MOD);
}
