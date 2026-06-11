#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1000010,mo=1e9+7;
int x,n,len,ans, a[maxn],b[maxn],c[maxn],f[maxn],base[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i],a[c[i]]=i;
    for(int i=1,x=0;i<=n;i++)x+=a[i],cout<<x<<" ";cout<<endl;
    for(int i=n,x=0;i>=1;i--)x+=a[i],b[i]=x;
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
}