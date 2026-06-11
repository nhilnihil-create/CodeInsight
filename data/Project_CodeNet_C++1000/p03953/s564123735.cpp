#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x[100010],p[100010],y[100010],a,cnt,res,t,siz[100010],ring[100010],ans;
bool f[100010];
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&x[i]),y[i]=x[i]-x[i-1],p[i]=i;
	scanf("%lld%lld",&m,&k);
	for (int i=1;i<=m;i++) {
		scanf("%lld",&a);
		swap(p[a],p[a+1]);
	}
	for (int i=1;i<=n;i++) if (!f[i]) {
		cnt++;
		res=i;
		while (!f[res]) {
			f[res]=true;
			siz[cnt]++;
			ring[res]=cnt;
			res=p[res];
		}
	}
	for (int i=1;i<=n;i++) {
		t=k%siz[ring[i]];
		res=i;
		while (t--) res=p[res];
		ans+=y[res];
		printf("%lld.0\n",ans);
	}	
}