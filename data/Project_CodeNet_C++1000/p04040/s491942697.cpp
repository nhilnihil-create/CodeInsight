#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<sstream>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
#define PI acos(-1.0)
#define pppp cout<<endl;
#define EPS 1e-8
#define LL long long
#define ULL unsigned long long     //1844674407370955161
#define INT_INF 0x3f3f3f3f      //1061109567
#define LL_INF 0x3f3f3f3f3f3f3f3f //4557430888798830399
// ios::sync_with_stdio(false);
// 那么cin, 就不能跟C的 scanf，sscanf, getchar, fgets之类的一起使用了。
const int dr[]= {0, 0, -1, 1, -1, -1, 1, 1};
const int dc[]= {-1, 1, 0, 0, -1, 1, -1, 1};
int read()//输入外挂
{
    int ret=0, flag=0;
    char ch;
    if((ch=getchar())=='-')
        flag=1;
    else if(ch>='0'&&ch<='9')
        ret = ch - '0';
    while((ch=getchar())>='0'&&ch<='9')
        ret=ret*10+(ch-'0');
    return flag ? -ret : ret;
}
const LL MOD=1000000007;
LL fac[1000005];
void getFac() //构造阶乘
{
    fac[0]=1;
    for(int i=1; i<=1000000; i++)
    {
        fac[i]=fac[i-1]*i%MOD;
    }
}
LL quickPowMod(LL a,LL b,LL mod) //快速幂
{
    LL res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
LL getC(LL n,LL m,LL mod) //获取C(n,m)%mod
{
    if(m>n)
        return 0;
    return fac[n]*(quickPowMod(fac[m]*fac[n-m]%mod,mod-2,mod))%mod;
}
LL Lucas(LL n,LL m,LL mod) //卢卡斯定理
{
    if(m==0)
        return 1;
    return getC(n%mod,m%mod,mod)*Lucas(n/mod,m/mod,mod)%mod;
}
int main()
{
    getFac();
    LL mod=1000000007;
    LL h,w,a,b;
    cin>>h>>w>>a>>b;
    LL ans=0;
    for(LL i=b+1;i<=w;++i)
        ans=(ans%mod+Lucas(h-a+i-2,i-1,mod)*Lucas(w-i+a-1,w-i,mod)%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}

