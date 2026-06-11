#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int h,w,a,b;
int cnt[70];
long long base[70],fac[200200];

long long inverse_md(long long num)
{
    long long val=1;
    int nw=0,po=1;
    base[0]=1;
    cnt[0]=0;
    base[1]=num;
    cnt[1]=1;
    while(nw+cnt[po]<=MOD-2)
    {
        val*=base[po];
        val%=MOD;
        nw+=cnt[po];
        base[po+1]=base[po]*base[po];
        base[po+1]%=MOD;
        cnt[po+1]=cnt[po]*2;
        po++;
    }
    for(int i=po;i>=0;i--)
    {
        if(nw+cnt[i]<=MOD-2)
        {
            val*=base[i];
            val%=MOD;
            nw+=cnt[i];
        }
    }
    //printf("%lld\n",(num*val)%MOD);
    return int(val);
}

long long sr(int dx,int dy)
{
    long long nw=fac[dx+dy];
    nw*=inverse_md(fac[dx]);
    nw%=MOD;
    nw*=inverse_md(fac[dy]);
    nw%=MOD;
    return nw;
}

main()
{
    fac[0]=fac[1]=1;
    for(int i=2;i<200020;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    scanf("%d %d %d %d",&h,&w,&a,&b);
    long long ans=0;
    for(int i=0;i<h-a;i++)
    {
        ans+=sr(i,b-1)*sr(h-1-i,w-1-(b));
        ans%=MOD;
        //printf("%lld %lld %lld\n",sr(i,b-1),sr(h-1-i,w-1-(b)),ans);
    }
    printf("%lld\n",ans);
}
