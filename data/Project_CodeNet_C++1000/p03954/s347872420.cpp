#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,a[N*2],b[N*2],l=1e9,r,g;
int chk(int x)
{
    for(int i=1;i<=n*2-1;i++) b[i]=(a[i]>=x)?1:0;b[0]=b[n*2]=2;
    for(int i=0;i<n;i++)
    {
        if((b[n-i]==b[n-i-1]&&b[n-i]==0)||(b[n+i]==b[n+i+1]&&b[n+i]==0)) return 0;
        if((b[n-i]==b[n-i-1]&&b[n-i]==1)||(b[n+i]==b[n+i+1]&&b[n+i]==1)) return 1;
    }
    return b[1];
}
int main()
{
    scanf("%d",&n);for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]),l=min(l,a[i]),r=max(r,a[i]);
    for(int mid=(l+r)>>1;l<=r;mid=(l+r)>>1) if(chk(mid)) l=mid+1,g=mid;else r=mid-1;
    printf("%d\n",g);
}