#include<bits/stdc++.h>
const int N=100007;
int n,m;
long long t1=0,t2=0,t3=0;
std::vector<int>e[N];
int col[N],un;
void dfs(int w,int c){
	if(!col[w])col[w]=c;
	else return void(un|=col[w]!=c);
	for(int i=0;i<e[w].size();++i)dfs(e[w][i],c^3);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,a,b;i<m;++i){
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=n;++i)t1+=e[i].empty();
	for(int i=1;i<=n;++i)if(e[i].size()&&!col[i]){
		un=0;
		dfs(i,1);
		++(un?t3:t2);
	}
	printf("%lld\n",t1*(n*2-t1)+t2*(t2+t3)*2+t3*t3);
	return 0;
}