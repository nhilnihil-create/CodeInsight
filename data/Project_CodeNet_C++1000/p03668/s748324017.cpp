#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>G[100010];
int SG[100010];
void dfs(int x,int fa=-1){for(int i:G[x])if(i!=fa)dfs(i,x),SG[x]^=SG[i]+1;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),x,y;
	for(int i=1;i<n;++i)x=gi(),y=gi(),G[x].push_back(y),G[y].push_back(x);
	dfs(1);
	if(SG[1])puts("Alice");
	else puts("Bob");
	return 0;
}
