#include<bits/stdc++.h>
typedef long long ll;
const int p=1e9+7;
int n,t,ans=1;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;++i)
    {
        scanf("%d",&x),++t;
        if(x<2*t-1)ans=(ll)ans*t--%p;
    }
    while(t)ans=(ll)ans*t--%p;
    printf("%d\n",ans);
    return 0;
}
