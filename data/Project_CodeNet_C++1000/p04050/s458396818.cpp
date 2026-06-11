#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int n,m,ck,a[N],b[N];
bool cmp(int a,int b){
	return (a&1)>(b&1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",a+i);
		ck+=(a[i]&1);
	}
	if(ck>2){
		puts("Impossible");
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	if(m==1){
		if(a[1]==1)
			printf("1\n1\n1");
		else printf("%d\n2\n%d %d",a[1],a[1]-1,1);
		return 0;
	}
	if(a[2]&1)
		swap(a[2],a[m]);
	for(int i=1;i<=m;i++)
		printf("%d ",a[i]);
	printf("\n%d\n%d ",m-(a[m]==1),a[1]+1);
	for(int i=2;i<m;i++)
		printf("%d ",a[i]);
	if(a[m]!=1)
		printf("%d ",a[m]-1);
	return 0;
}