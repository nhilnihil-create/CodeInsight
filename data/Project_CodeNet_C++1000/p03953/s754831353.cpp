#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef double db;
const int N=1e5+10;
int n,m,tot,st,d[N],x,id[N],nt[N],K,ans[N],q[N],cnt,vs[N],p[N];
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for (int i=2;i<=n;i++)d[i]=p[i]-p[i-1],id[i]=i;
	scanf("%lld%lld",&m,&K);
	for (int i=1;i<=m;i++){
		scanf("%lld",&x);
		swap(id[x],id[x+1]);
	}
	for (int i=2;i<=n;i++) nt[id[i]]=i;
	for (int i=2;i<=n;i++)
		if (!vs[i]){
			int cnt=0;
			for (int j=i;!vs[j];j=nt[j]){
				q[++cnt]=j;
				vs[j]=1;
			}
			x=K%cnt;int k=x%cnt+1;
			for (int j=1;j<=cnt;j++){
				ans[q[k]]=d[q[j]];
				k=k==cnt?1:(k+1);
			}
		}
	double pos=p[1];
	for (int i=1;i<=n;i++){
		pos+=ans[i];
		printf("%.10lf\n",(db)pos);
	}
	return 0;
}