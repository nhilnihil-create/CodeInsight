#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
int s[511][511],n,m,d;
vector<par>g;
set<par>st;
void dfs(int x,int y,int v){
	if(st.count(par(x,y)))return ;
	st.insert(par(x,y));
	bool flag=0;
	for(int i=0;i<g.size();++i){
		int a=x+g[i].first,b=g[i].second+y;
		if(a>=1&&a<=n&&b>=1&&b<=m)s[a][b]=v,flag=1;//printf("[%d,%d]",a,b);
	}
	if(!flag)return ;
	dfs(x+d,y+d,v^2),dfs(x-d,y-d,v^2);
	dfs(x+d,y-d,v^1),dfs(x-d,y+d,v^1);
}
int main(){
	scanf("%d%d%d",&n,&m,&d);
	if(d&1){
		for(int i=0;i<n;++i,puts(""))for(int j=0;j<m;++j)
			printf("%c",(i+j)&1?'R':'G');
		return 0;
	}  else {
		for(int i=0;i<d;++i)g.push_back(par(i,0));
		for(int i=1;i<=d/2;++i)for(int j=0;j<d-i*2;++j)
			g.push_back(par(i+j,i)),g.push_back(par(i+j,-i));
		d/=2;
		dfs(1,1,0);
		for(int i=1;i<=n;++i,puts(""))
			for(int j=1;j<=m;++j)
				switch(s[i][j]){
					case 0:putchar('R');break;
					case 1:putchar('G');break;
					case 2:putchar('B');break;
					case 3:putchar('Y');break;
				}	
	}
}