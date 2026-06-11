#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int h,w,n,a,g[105][105],d[4][2]={-1,0,0,1,1,0,0,-1};
queue<int> q;
void dfs(int i,int j,int di){
	g[i][j]=q.front(),q.pop();
	int ti=i+d[di][0],tj=j+d[di][1];
	if(ti>=h||ti<0||tj>=w||tj<0||g[ti][tj]) di=(di+1)%4,ti=i+d[di][0],tj=j+d[di][1];
	if(!g[ti][tj]) dfs(ti,tj,di);
}
int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		while(a--) q.emplace(i);
	}
	dfs(0,0,1);
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) printf("%d%c",g[i][j],j==w-1?'\n':' ');
	return 0;
}