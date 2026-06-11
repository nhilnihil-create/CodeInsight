#include<bits/stdc++.h>
using namespace std;
int ans[100001];
int w[100001];
int x[100001];
int n,l,t,cur;
int main()
{
    scanf("%d%d%d",&n,&l,&t);
    for(register int i=1;i<=n;++i) scanf("%d%d",&x[i],&w[i]);
    for(register int i=1;i<=n;++i)
        if(w[i]==1)
        {
            ans[i]=(x[i]+t)%l;
            cur+=(x[i]+t)/l;
        }
        else
        {
            ans[i]=(x[i]-t)%l;
            cur+=(x[i]-t)/l;
            if(ans[i]<0) --cur,ans[i]+=l;
        }
    ((cur%=n)+=n)%=n;
    sort(ans+1,ans+n+1);
    for(register int i=cur+1;i<=n;++i) printf("%d\n",ans[i]);
    for(register int i=1;i<=cur;++i) printf("%d\n",ans[i]);
    return 0;
}