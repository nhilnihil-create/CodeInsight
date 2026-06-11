#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
struct edge{
	int pre,to;
	#define pre(i) ed[i].pre
	#define to(i) ed[i].to
}ed[100010];
int cnt,head[100010];
void merge(int a,int b){
	++cnt;
	to(cnt)=b;
	pre(cnt)=head[a];
	head[a]=cnt;
}
int n,k,ans;
int a[100010],seg[100010];
void dfs(int x,int pre){
	for(int t=head[x];t;t=pre(t)){
		int l=to(t);
		dfs(l,x);
		seg[x]=max(seg[x],seg[l]+1);
	}
	if(seg[x]>=k-1&&x!=1&&pre!=1){
		ans++;
		seg[x]=-1;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int t=1;t<=n;++t){
		scanf("%d",&a[t]);
		if(t!=1)merge(a[t],t);
	}
	if(a[1]!=1)ans++;
	dfs(1,0);
	printf("%d",ans);
}