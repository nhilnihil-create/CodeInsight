#include<bits/stdc++.h>
using namespace std;
int n,f[1000005];
const int p = 1000000007;
int main()
{
    scanf("%d",&n);
    int ans=0;
    f[0]=f[1]=1;int sm=2;
    for(int i=2;i<=n;i++)
    {
        f[i]=(sm-f[i-2]+p)%p;
        (sm+=f[i])%=p;
    }
    for(int i=0;i<n-1;i++)
    {
        ans+=1LL*f[i]*(n-1)%p*(n-1)%p;
        ans%=p;
        ans+=1LL*f[i]*(i+1)%p;
        ans%=p;
    }
    ans+=1LL*f[n-1]*(n-1)%p;
    ans%=p;
    ans+=f[n];
    ans%=p;
    cout<<ans<<endl;
    return 0;
}
