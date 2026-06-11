#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],b[N],c[N];
int main()
{
    int n,ans=0;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    for(int i=1;i<=n;i++)c[a[i]]=i;
    for(int i=1;i<=n;i++)if(abs(c[i]-i)%2)ans++;
    cout<<ans/2<<endl;
}
