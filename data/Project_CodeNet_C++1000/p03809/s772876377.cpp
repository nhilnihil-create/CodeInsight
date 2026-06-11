#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int n,now,a[N],v[M],b[N],nex[M],head[N];
void addedges(int x,int y){
	nex[++now]=head[x];
	head[x]=now,v[now]=y;
}
int dfs(int x,int fa){
	int res=0,mx=0;
	if(b[x]==1)	return a[x];
	for(int i=head[x];i;i=nex[i])
		if(v[i]!=fa){
			int k=dfs(v[i],x);
			if(k==-1)	return -1;
			res+=k,mx=max(mx,k);
		}
	int up=(a[x]*2-res);
	if(res<up||up<0||2*mx-res>up||res<up)	return -1;
	return up;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	if(n==2){
		if(a[1]==a[2])	puts("YES");
		else	puts("NO");
		return 0;
	}
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		addedges(x,y),++b[x];
		addedges(y,x),++b[y];
	}
	for(int i=1;i<=n;i++)
		if(b[i]!=1){
			addedges(0,i);
			if(dfs(0,0)!=-1)	puts("YES");
			else	puts("NO");
			break;
		}
	return 0;
}
