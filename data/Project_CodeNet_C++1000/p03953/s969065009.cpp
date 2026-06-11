#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010],ans[100010];
int c[100010],b[100010],d[100010];
int main() {
    int n; scanf("%d",&n);
    int i; ll sum=0; for(i=1;i<=n;i++) { scanf("%lld",&a[i]); a[i]-=sum; sum+=a[i]; c[i]=i; }
    int m; ll k; scanf("%d%lld",&m,&k); int x; for(i=1;i<=m;i++) { scanf("%d",&x); swap(c[x],c[x+1]); }
    for(i=1;i<=n;i++) if(!b[i]) { int cnt=0; int j; for(j=i;!b[j];j=c[j]) { b[j]=1; d[++cnt]=j; } for(j=1;j<=cnt;j++) ans[d[j]]=a[d[(j+k-1)%cnt+1]]; }
    for(i=1;i<=n;i++) { ans[i]+=ans[i-1]; printf("%lld.0\n",ans[i]); }
    return 0;
}
