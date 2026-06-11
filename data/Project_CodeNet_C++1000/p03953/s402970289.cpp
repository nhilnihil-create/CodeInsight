#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;
typedef long long ll;
#define N 100050
int n,a[N],m,p[N],vis[N],b[N],lb;ll X[N],d[N],K,ans[N];
int main() {
	scanf("%d",&n);
	int i,y=0,j;
	for(i=1;i<=n;i++) scanf("%lld",&X[i]),d[i]=X[i]-X[i-1];
	scanf("%d%lld",&m,&K);
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=m;i++) swap(p[a[i]],p[a[i]+1]);
	for(i=1;i<=n;i++) if(!vis[i]) {
		int x=i;lb=0;
		for(;!vis[x];x=p[x]) {
			vis[x]=1;
			b[lb++]=x;
		}
		for(int i=0;i<lb;i++) {
			ans[b[i]]=d[b[(i+K)%lb]];
		}
	}
	for(i=1;i<=n;i++) X[i]=ans[i]+X[i-1];
	for(i=1;i<=n;i++) printf("%lld.0\n",X[i]);
}
