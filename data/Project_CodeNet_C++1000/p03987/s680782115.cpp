#include <bits/stdc++.h>
#include<cstdio>
#define int long long
using namespace std;
int n,top,minn;
const int N=1000010;
int a[N],zhan[N],r[N],l[N];
long long ans;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
    for(int i=1;i<=n;++i)r[i]=n+1,l[i]=0;
    for(int i=1;i<=n;++i)
    {
        while(top&&a[zhan[top]]>a[i])r[zhan[top--]]=i;
        l[i]=zhan[top];
        zhan[++top]=i;
    }
    for(int i=1;i<=n;++i)ans+=(r[i]-i)*(i-l[i])*a[i];
    cout<<ans;
    return 0;
}