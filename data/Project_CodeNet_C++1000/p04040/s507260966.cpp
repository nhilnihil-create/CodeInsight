#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define G  1100000
#define mod 1000000007
LL pri[G];
LL ni[G],ans;
LL pow(LL a,int b)
{
    LL ans=1,base=a;
    while (b>0)
    {
        if (b%2==1)
            ans=(base*ans)%mod;
        base=(base*base)%mod;
        b/=2;
    }
    return ans;
}
void s()   //打表
{
    pri[0]=1;
    ni[0]=1;
    for (int i=1;i<G ;i++)
    {
        pri[i]=pri[i-1]*i%mod;  //N！
        ni[i]=pow(pri[i],mod-2);
    }
}
LL ANS(LL n,LL m)
{
    LL ans;
    ans=((pri[n]*ni[m]%mod)*ni[n-m])%mod;
    return ans%mod;
}
int main()
{
    //cout<<(22183738317301)%mod<<endl;
    s();
    LL H,W,A,B;
    scanf("%lld%lld%lld%lld",&H,&W,&A,&B);
    LL ans=0;
    for(LL i=B+1;i<=W;i++)
    {
        ans+=(LL)(ANS(H-A+i-2,H-A-1)*ANS(W+A-i-1,A-1)%mod)%mod;
    }
    printf("%lld\n",ans%mod);
    /*
    int t,n,b,k=1;
	//scanf("%d",&t);
    while (t--)
    {
        //scanf("%d%d",&n,&b);
        //ans=((pri[n]*ni[b]%mod)*ni[n-b])%mod; // C（n，m）= n！/（m！*（n-m）！）
        printf("Case %d: %lld\n",k++,ans);
    }
    return 0;  */

}
