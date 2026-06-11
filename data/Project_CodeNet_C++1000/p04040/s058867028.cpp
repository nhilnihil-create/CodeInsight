#include<bits/stdc++.h>
using namespace std;

const int md = 1000000007;

int h,w,a,b;
long long fac[200200];
long long ans;

void gen_fac()
{
    fac[0]=1;
    for(int i=1;i<200020;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=md;
    }
}

int inv_mod(long long num,long long tar) {
    long long pw[40];
    long long pwval=1,cur=1;
    pw[0]=1;
    pw[1]=num;
    while(pwval*2<=tar)
    {
        pw[cur+1]=pw[cur]*pw[cur];
        pw[cur+1]%=md;
        pwval*=2;
        cur++;
    }
    long long ret = pw[cur];
    long long left = tar-pwval;
    pwval/=2;
    for(int i=cur-1;i>=0;i--,pwval/=2)
    {
        if(pwval<=left)
        {
            left-=pwval;
            ret*=pw[i];
            ret%=md;
        }
    }
    return (int)ret;
}

main()
{
    gen_fac();
    scanf("%d %d %d %d",&h,&w,&a,&b);
    int rigth_sign1=b-1;
    int rigth_sign2=w-b-1;
    for(int i=0;i<h-a;i++)
    {
        int down_sign1=i;
        int down_sign2=h-i-1;
        long long pls=fac[rigth_sign1+down_sign1]*inv_mod(fac[rigth_sign1],md-2);
        pls%=md;
        pls*=inv_mod(fac[down_sign1],md-2);
        pls%=md;
        pls*=fac[rigth_sign2+down_sign2];
        pls%=md;
        pls*=inv_mod(fac[rigth_sign2],md-2);
        pls%=md;
        pls*=inv_mod(fac[down_sign2],md-2);
        pls%=md;
        //printf("%lld\n",pls);
        ans+=pls;
        ans%=md;
    }
    printf("%lld\n",ans);
}
