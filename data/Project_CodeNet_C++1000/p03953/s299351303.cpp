#include<bits/stdc++.h>
#define N 100009
using namespace std;

int n,m,a[N],b[N],p[N],q[N],np[N]; long long tot;
int main(){
	scanf("%d",&n);
	int i; long long now; 
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	scanf("%d%lld",&m,&tot);
	for (i=1; i<=m; i++) scanf("%d",&b[i]);
	for (i=1; i<n; i++) p[i]=i;
	for (i=1; i<=m; i++) swap(p[b[i]-1],p[b[i]]);
	for (i=1; i<n; i++) q[i]=i;
	for (; tot; tot>>=1){
		if (tot&1){
			for (i=1; i<n; i++) np[i]=q[p[i]];
			for (i=1; i<n; i++) q[i]=np[i];
		}
		for (i=1; i<n; i++) np[i]=p[p[i]];
		for (i=1; i<n; i++) p[i]=np[i];
	}
	for (i=n; i>1; i--) a[i]-=a[i-1];
	for (i=1,now=a[1]; i<=n; now+=a[q[i]+1],i++)
		printf("%lld\n",now);
	return 0;
}
