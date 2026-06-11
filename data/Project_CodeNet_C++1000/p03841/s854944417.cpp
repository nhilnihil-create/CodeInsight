#include<bits/stdc++.h>
#define N 509
using namespace std;

int n,m,a[N],ans[N*N],q[N];
void gg(){
	puts("No"); exit(0);
}
bool cmp(int x,int y){ return a[x]<a[y]; }
int main(){
	scanf("%d",&n); m=n*n;
	int i,j,k,l;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if (ans[a[i]]) gg(); ans[a[i]]=i;
	}
	for (i=1; i<=n; i++) q[i]=i;
	sort(q+1,q+n+1,cmp);
	for (l=1; l<=n; l++){
		i=q[l];
		for (j=1,k=1; j<a[i] && k<i; j++) if (!ans[j]){
			ans[j]=i; k++;
		}
		if (k<i) gg();
	}
	for (l=n; l; l--){
		i=q[l];
		for (j=m,k=n; j>a[i] && k>i; j--) if (!ans[j]){
			ans[j]=i; k--;
		}
		if (k>i) gg();
	}
	puts("Yes");
	for (i=1; i<=m; i++) printf("%d%c",ans[i],(i<m)?' ':'\n');
	return 0;
}
