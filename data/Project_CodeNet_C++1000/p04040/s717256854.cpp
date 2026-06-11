#include<bits/stdc++.h>
using namespace std;
long long fac[500005],infac[500005];
long long in(long long p)
{
    int po=1000000005;
    long long ps=1,ps2=p;
    while(po!=0)
    {
        if(po%2==1)
        {
            ps*=ps2;
            ps%=1000000007;
        }
        ps2*=ps2;
        ps2%=1000000007;
        po/=2;
    }
    return ps;
}
long long se(int a,int b)
{
    long long cal=(fac[a]*infac[b])%1000000007;
    cal=(cal*infac[a-b])%1000000007;
    return cal;
}
main()
{
    fac[0]=1;
    infac[0]=1;
    for(int i = 1;i < 500005;i++)
    {
        fac[i]=(fac[i-1]*i)%1000000007;
        infac[i]=in(fac[i]);
    }
	int m,n,a,b;
    scanf("%d%d%d%d",&m,&n,&a,&b);
    long long cs=0;
    for(int i = m-a+1;i <= m;i++)
    {
        long long cs2=se(b+i-2,i-1)*se(m-i+n-b-1,n-b-1);
        //printf("%lld\n\n",se(b+i-2,i-1));
        cs+=cs2;
        cs%=1000000007;
    }
    long long cs3=0;
    cs3+=se(m+n-2,n-1);
    cs3+=1000000007;
    cs3-=cs;
    cs3%=1000000007;
    printf("%lld",cs3);
}
