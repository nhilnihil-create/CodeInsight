#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050
double a[N],c[N],d[N];
int p[N],b[N],n,m,i,j,top,sta[N];
long long k;
bool vis[N];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%lf",&a[i]);
	for (i=1;i<n;i++) p[i]=i;
	scanf("%d%lld",&m,&k);
	while (m--){
		int x;scanf("%d",&x);
		swap(p[x-1],p[x]);
	}
	for (i=1;i<n;i++) if (!vis[i]){
		top=0;
		sta[top]=i;vis[sta[top]]=true;
		while (p[sta[top]]!=i) sta[++top]=p[sta[top-1]],vis[sta[top]]=true;
		for (j=0;j<=top;j++) b[sta[j]]=sta[(j+k%(top+1))%(top+1)];
	}
	for (i=1;i<n;i++) c[i]=a[i+1]-a[i];
	for (i=1;i<n;i++) d[i]=c[b[i]];
	for (i=2;i<=n;i++) a[i]=a[i-1]+d[i-1];
	for (i=1;i<=n;i++) printf("%.10f\n",a[i]);
	return 0;
}