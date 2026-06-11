#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int a[N],pre[N],lst[N],q[N],tt=0;
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    pre[1]=1;q[++tt]=1;
    for(int i=2;i<=n;i++)
    {
        while(tt&&a[q[tt]]>a[i])tt--;
        pre[i]=tt?q[tt]+1:1;q[++tt]=i;
    }
    tt=0;lst[n]=n;q[++tt]=n;
    for(int i=n-1;i;i--)
    {
        while(tt&&a[q[tt]]>a[i])tt--;
        lst[i]=tt?q[tt]-1:n;q[++tt]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=1ll*a[i]*(i-pre[i]+1)*(lst[i]-i+1);
    cout<<ans<<endl;
}
