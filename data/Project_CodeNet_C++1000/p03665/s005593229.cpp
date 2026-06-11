#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,a[100001],f[100001][2];
signed main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==0)
        f[i][0]=2*f[i-1][0],f[i][1]=2*f[i-1][1];
        else
        f[i][0]=f[i-1][1]+f[i-1][0],f[i][1]=f[i-1][0]+f[i-1][1];
    }
    cout<<f[n][p];
}