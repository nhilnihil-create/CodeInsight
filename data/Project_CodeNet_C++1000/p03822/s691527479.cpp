#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],l,x,y,fi[N],ne[N],tot,zz[N],n,dp[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void down(int x){
	int i=x;
	if (x*2<=l&&a[x]>a[x*2])i=x*2;
	if (x*2<l&&a[i]>a[x*2+1])i=x*2+1;
	if (i!=x){
		swap(a[x],a[i]);
		down(i);
	}
}
void up(int x){
	if (x==1)return;
	if (a[x]<a[x/2]){
		swap(a[x],a[x/2]);
		up(x/2);
	}
}
void dfs(int x){
	for (int i=fi[x];i;i=ne[i])dfs(zz[i]);
	int l=0;
	for (int i=fi[x];i;i=ne[i])a[++l]=dp[zz[i]];
	sort(a+1,a+l+1);
	for (int i=1;i<=l;i++)dp[x]=max(a[i]+l-i+1,dp[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n;i++){
		scanf("%d",&x);
		jb(x,i);
	}
	dfs(1);
	printf("%d\n",dp[1]);
}