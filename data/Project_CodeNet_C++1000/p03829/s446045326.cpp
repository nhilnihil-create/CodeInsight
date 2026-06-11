#include<bits/stdc++.h>
long long n,a,b,ans,x[233333];
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<n;i++)ans+=std::min(b,a*(x[i+1]-x[i]));
    printf("%lld\n",ans);
}