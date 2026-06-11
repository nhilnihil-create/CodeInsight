#include<bits/stdc++.h>
using namespace std;
char p[300005][10];
long long qs[300005],qs2[300005];
main()
{
	int t,ck=1,ck2=0;
    long long s,cal=0,tmp=0;
    scanf("%d",&t);
    for(int i = 1;i <= 2*t-1;i++)
    {
        if(i%2==1)
        {
            scanf("%lld",&qs[i/2+1]);
            long long cs=qs[i/2+1];
            if(p[i/2][0]=='-')
            cs=-cs;
            qs2[i/2+1]=qs2[i/2]+cs;
            //printf("%lld-->",qs2[i/2+1]);
        }
        else
        {
            scanf("%s",p[i/2]);
        }
    }
    long long cas=0,mx=qs2[t];
    for(int i = t;i >= 1;i--)
    {
        cas+=qs[i];
        qs[i]+=qs[i+1];
        if(p[i-1][0]=='-')
        {
            //printf("-->");
            mx=max(mx,qs2[i-1]-2*cas+qs[i]);
            //printf("pos = %d    %lld<--%lld\n",i,mx,qs2[i-1]-2*cas+qs[i]);
            cas=0;
        }
    }
    printf("%lld",mx);
}
