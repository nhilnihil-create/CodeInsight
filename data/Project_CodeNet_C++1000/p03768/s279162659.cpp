#include <bits/stdc++.h>
#define regi register int
int n,m,q;
int pos[200001],d[200001],c[200001];
int color[200001][20];
std::vector<int>e[300001];
inline int read(){int r=0,c=0,w;for(;!isdigit(c=getchar());r=c);for(w=c^48;isdigit(c=getchar());w=w*10+(c^48));return r^45?w:-w;}
void dfs(int x, int d, int c){
	if(color[x][d]||d==-1)
	  return;
	color[x][d]=c;
	for(regi i=0;i<e[x].size();++i) {
		regi y=e[x][i];
		dfs(y,d-1,c);
	}
	dfs(x,d-1,c);
}
main(){
  n=read();
  m=read();
	for(regi i=1,x,y;i<=m;++i){
		x=read();
		y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	q=read();
	for(regi i=1;i<=q;++i){
		pos[i]=read();
		d[i]=read();
		c[i]=read();
	}
	for(regi i=q;i;--i)
		dfs(pos[i],d[i],c[i]);
	for(regi i=1;i<=n;++i)
		printf("%d\n",color[i][0]);
	return 0;
}