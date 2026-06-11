#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+2;
int n,m;
int a[maxn],d[maxn],res[maxn],tmp[maxn];
LL k;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) d[i]=res[i]=i;
	scanf("%d%lld",&m,&k);
	for (int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		swap(d[x-1],d[x]);
	}
	while (k){
		if (k&1) for (int i=1;i<n;i++) res[i]=d[res[i]];
		for (int i=1;i<n;i++) tmp[i]=d[d[i]];
		memcpy(d,tmp,n<<2);
		k>>=1;
	}
	LL ans=a[1];
	for (int i=1;i<=n;i++){
		printf("%lld.0\n",ans);
		ans+=a[res[i]+1]-a[res[i]];
	}
	return 0;
}