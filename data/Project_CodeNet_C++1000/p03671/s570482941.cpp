#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,ans;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(a>=b&&a>=c)
    {
        ans=b+c;
        printf("%lld\n",ans);
    }
    else if(b>=c&&b>=a)
    {
        ans=c+a;
        printf("%lld\n",ans);
    }
    else
    {
        ans=a+b;
    printf("%lld\n",ans);
    }


}
