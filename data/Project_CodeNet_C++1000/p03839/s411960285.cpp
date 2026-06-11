#include <iostream>
using namespace std;
int a[100010];
long long num[100010],t[100010],sum[100010];
int main(){
    int n,k;
    long long ans=0;
    cin>>n>>k;
    int i;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    for(i=1;i<=n;i++)num[i]=num[i-1]+max(a[i],0);
    for(i=n;i>=1;i--)t[i]=t[i+1]+max(a[i],0);
    for(i=0;i<=n-k;i++)
    ans=max(ans,num[i]+t[i+k+1]+max(sum[i+k]-sum[i],0LL));
    cout<<ans<<endl;
    return 0;
}
