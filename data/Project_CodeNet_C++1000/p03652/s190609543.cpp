#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
struct node{
	int cnt,id;
}ath[100005];
int used[100005];
int a[305][305];
bool cmp(node a,node b){
	return a.cnt>b.cnt;
}
int main(){
//	freopen("sports.in","r",stdin);
//	freopen("sports.out","w",stdout);
	int n,m,i,j,k,o,p,l;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)ath[i].id=i;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		scanf("%d",&a[i][j]);
		if(j==1)ath[a[i][j]].cnt++;
	}
	int ans=1<<30;
	int xm=m;
	while(xm--){
		sort(ath+1,ath+1+m,cmp);
		ans=min(ans,ath[1].cnt);
		used[ath[1].id]=1;
		for(i=1;i<=m;i++)ath[i].id=i,ath[i].cnt=0;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(used[a[i][j]]==0){
			ath[a[i][j]].cnt++;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}