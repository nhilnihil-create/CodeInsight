#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,tot,a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if(a[i]%2){
			tot++;
		}
	}
	if(m==1){
		if(a[1]==1){
			printf("1\n1\n1\n");
		}else{
			printf("%d\n2\n1 %d\n",a[1],a[1]-1);
		}
		return 0;
	}
	if(tot>2){
		puts("Impossible");
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(a[i]%2){
			swap(a[1],a[i]);
			break;
		}
	}
	for(int i=2;i<=m;i++){
		if(a[i]%2){
			swap(a[m],a[i]);
			break;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",a[i]);
	}
	puts("");
	if(a[m]!=1){
		printf("%d\n",m);
		printf("%d ",a[1]+1);
		for(int i=2;i<m;i++){
			printf("%d ",a[i]);
		}
		printf("%d ",a[m]-1);
	}else{
		printf("%d\n",m-1);
		printf("%d ",a[1]+1);
		for(int i=2;i<m;i++){
			printf("%d ",a[i]);
		}
	}
	puts("");
	return 0;
}