#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 220000
using namespace std;
int fa[N],a[N],b[N],sum[N];
int n,m,bns,tot;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),bns+=a[i]&1;
	if(bns>2){
		printf("Impossible\n");
		return 0;
	}
	for(int i=2;i<=m;i++){
		if((a[i]%2==1)&&(a[1]%2==0))swap(a[1],a[i]);
		if((a[i]%2==1)&&(a[m]%2==0))swap(a[m],a[i]);
	}
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	printf("\n");
	if(m==1){
		if(a[1]==1){
			printf("1\n");
			printf("1\n");
			return 0;
		}
		printf("2\n");
		printf("%d %d",a[1]-1,1);
		return 0;
	}
	int ans=m;
	if(a[1]==1)ans--;
	ans+=a[m]%2==0;
	printf("%d\n",ans);
	if(a[1]-1)printf("%d ",a[1]-1);
	for(int i=2;i<m;i++)printf("%d ",a[i]);
	if(a[m]&1)printf("%d ",a[m]+1);
	else printf("%d %d",a[m],1);
}