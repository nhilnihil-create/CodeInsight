#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=1e9+7;
const int maxn=1e5+10;
ll ans=1;
int n,x[maxn];
int main()
{
    cin>>n;int i,j;
    for(i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(i=1,j=0;i<=n;i++)
        if(x[i]<2*(i-j)-1)
            (ans*=i-j)%=p,++j;
    for(;j<n;j++) (ans*=n-j)%=p;
    cout<<ans;
    return 0;
}