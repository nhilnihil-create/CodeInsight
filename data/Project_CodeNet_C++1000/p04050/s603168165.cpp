#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[200005],b[200005],sum;
bool vis[200005];
bool cmp(int a,int b){
	if((a&1)!=(b&1)) return (a&1)>(b&1);
	return a>b;
}
int main(){
	scanf("%d%d",&n,&m);
	int tot=0;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if(a[i]&1) tot++;
	}
	if(tot>2) return puts("Impossible"),0;
	if(m==1){
		if(n>1)printf("%d\n2\n%d %d\n",n,n-1,1);
		else printf("1\n1\n1");
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	tot=0;
	if(a[2]&1) swap(a[2],a[m]);
	for(int i=1;i<=m;i++) printf("%d ",a[i]);
	puts("");
	b[++sum]=a[1]-1;
	if(a[1]==1) sum=0;
	for(int i=2;i<m;i++){
		b[++sum]=a[i];
	}
	if(m>1) b[++sum]=a[m]+1;
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++) printf("%d ",b[i]);
	return 0;
}