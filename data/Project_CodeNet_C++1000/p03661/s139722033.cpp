#include<iostream>
using namespace std;
const int N=200100;
long long abs_(long long x)
{
    if(x<0) x=-x;
    return x;
}
long long ans,n,a[N],sum[N],sumd[N];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
        sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;--i)
        sumd[i]=sumd[i+1]+a[i];
    ans=0x3fffffffffffffff;
    for(int i=1;i<n;++i)
        ans=min(ans,abs_(sum[i]-sumd[i+1]));
    cout<<ans<<endl;
    return 0;
}