#include <bits/stdc++.h>

#define N 200010
#define M 400010

using namespace std;

int ans[N];
int ver[M],nex[M],head[N],nu;
int n,x1,x2;

inline int read(){
	int x=0;char c=getchar();
	for(;c<'0' || c>'9';c=getchar());
	for(;c>='0' && c<='9';c=getchar()) x=(x<<1)+(x<<3)+c-48;
	return x;
}

inline void add(int x,int y){
	ver[++nu]=y;nex[nu]=head[x];head[x]=nu;
}

void dfs(int x,int fa){
	for(int i=head[x];i;i=nex[i]){
		int y=ver[i];
		if(y!=fa)
		{
			dfs(y,x);
			ans[x]^=(ans[y]+1);
		}	
	}
	return;
}

int main(){
	n=read();
	for(int i=1;i<n;i++)
	x1=read(),x2=read(),add(x1,x2),add(x2,x1);
	dfs(1,0);
	if(!ans[1]) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}                                                                                                                                                                                                                     