#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

const int N=100005;

int n,m,t,pos,cnt;
ll k;
double ans;
int x[N],a[N],p[N],f[N],b[N];
bool vis[N];

int main(){
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&x[i]);
	for (i=n;i>=1;i--) x[i]-=x[i-1];
	for (i=1;i<=n;i++) p[i]=i;
	scanf("%d%lld",&m,&k);
	for (i=1;i<=m;i++) scanf("%d",&a[i]);
	for (i=1;i<=m;i++) swap(p[a[i]],p[a[i]+1]);
	for (i=1;i<=n;i++) if (!vis[i]){
		pos=i; cnt=0;
		a[cnt]=i;
		while (p[pos]!=i){
			pos=p[pos];
			a[++cnt]=pos;
		}
		f[i]=a[k%(cnt+1)];
		for (j=1;j<=cnt;j++) f[a[j]]=p[f[a[j-1]]];
		for (j=0;j<=cnt;j++) vis[a[j]]=1;
	}
	for (i=1;i<=n;i++){
		ans+=(double)x[f[i]];
		printf("%.1f\n",ans);
	}
	return 0;
}