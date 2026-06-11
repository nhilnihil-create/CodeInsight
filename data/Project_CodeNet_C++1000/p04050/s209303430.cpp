#include<bits/stdc++.h>
#define N 109
using namespace std;

int m,n,cnt,a[N],b[N],ans[N];
void add(int x){ ans[++cnt]=x; }
int main(){
	scanf("%d%d",&m,&n);
	int i,j;
	for (i=1,j=0; i<=n; i++){
		scanf("%d",&a[i]);
		if (a[i]&1) j++;
	}
	if (j>2){
		puts("Impossible"); return 0;
	}
	for (i=1; i<=n; i++) if (a[i]&1){
		swap(a[1],a[i]); break;
	}
	for (i=n; i>1; i--) if (a[i]&1){
		swap(a[i],a[n]); break;
	}
	for (i=1; i<=n; i++) printf("%d%c",a[i],(i<n)?' ':'\n');
	if (n==1){
		if (a[1]==1){ puts("1"); puts("1"); }
		else{ puts("2"); printf("1 %d\n",a[1]-1); }
		return 0;
	}
	add(a[1]+1);
	for (i=2; i<n; i++) add(a[i]);
	if (a[n]>1) add(a[n]-1);
	printf("%d\n",cnt);
	for (i=1; i<=cnt; i++) printf("%d%c",ans[i],(i<cnt)?' ':'\n');
	return 0;
}
