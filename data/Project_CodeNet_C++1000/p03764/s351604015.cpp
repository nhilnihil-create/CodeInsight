#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,x;
int main()
{
    scanf("%d%d",&n,&m);
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        ans1=(ans1+1LL*(2*i-n-1)*x%mod)%mod;
    }
    for (int i=1;i<=m;i++) {
        scanf("%d",&x);
        ans2=(ans2+1LL*(2*i-m-1)*x%mod)%mod;
    }
    printf("%d\n",1LL*ans1*ans2%mod);
    return 0;
}
