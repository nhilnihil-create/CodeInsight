#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 520
using namespace std;
struct node{
	int x,id,sum;
}b[N];
int ans[N*N],p[N];
int n,a[N],head,tot;
bool cmp(node x,node y){
	return x.x<y.x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i].x=a[i];
		b[i].id=i;
		b[i].sum=n-i;
	}
	sort(b+1,b+1+n,cmp);
	head=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		int k=b[i].x;
		int o=b[i].id;
		int tot=0;
		for(int i=1;i<=k-1;i++){
			if(tot==o-1)break;
			if(ans[i]==0)ans[i]=o,tot++;
		}
		ans[k]=o;
	}
	for(int i=1;i<=n*n;i++){
		if(ans[i])continue;
		if(head==n&&b[head].sum==0)break;
		while(b[head].sum==0&&head<n)head++;
		b[head].sum--;
		ans[i]=b[head].id;
	}
	for(int i=1;i<=n*n;i++){
		p[ans[i]]++;
		if(ans[i]==p[ans[i]]){
			if(a[ans[i]]!=i){
				printf("No\n");
				exit(0);
			}
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n*n;i++)printf("%d ",ans[i]);
}