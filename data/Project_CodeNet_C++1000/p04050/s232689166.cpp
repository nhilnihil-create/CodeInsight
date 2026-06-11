#include<bits/stdc++.h>
#define M 100005
#define YXQAK {printf("Impossible\n"); return 0;}
using namespace std;

int a[M]={0},aa[M]={0};
int n,m,ji=0,now=1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",aa+i);
		if(aa[i]&1) ji++;
	}
	if(ji>2) YXQAK
	if(ji==0){
		for(int i=1;i<=m;i++) a[i]=aa[i];
	}else{
		for(int i=1;i<=m;i++){
			if(aa[i]&1){
				if(a[1]==0) a[1]=aa[i];
				else a[m]=aa[i];
			}else a[++now]=aa[i];
		}
	}
	if(m==1){
		printf("%d\n",aa[1]);
		if(aa[1]==1) printf("1\n1\n");
		else printf("2\n%d %d\n",aa[1]-1,1);
		return 0;
	}
	for(int i=1;i<=m;i++) printf("%d ",a[i]);
	printf("\n");
	a[1]++; a[m]--; if(a[m]==0) m--;
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%d ",a[i]);
}