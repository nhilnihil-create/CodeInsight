#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
typedef long long  LL;
using namespace std;
const LL INF = 0x3f3f3f3f;

LL n,A,B;
LL d[100009];
bool judge(LL mid)
{
    LL ans=mid;
    for(int i = 1;i<=n;i++)
    {
        LL cn=d[i]-mid*B;
        if(cn>0)
        {
            LL temp=cn/(A-B)+(cn%(A-B)==0?0:1);//TEMP表示当一个怪物被所求值的B打后 是否还需要被A打   这里就差不多应该是来判断A具体攻击谁 攻击几次
            ans-=temp;//ans是一共A攻击的次数，如果A攻击次数归零 还没攻击完 说明这个次数是无法消灭全部的，所以返回falsh
            if(ans<0)
                return false;
        }

    }
    return true;
}

int main()
{


  cin>>n>>A>>B;

    LL l=0;
    LL r= INF;
    LL ans=INF;
   for(int i = 1;i<=n;i++)
        cin>>d[i];
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(judge(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }

    printf("%lld\n",ans);

    return 0;


}
