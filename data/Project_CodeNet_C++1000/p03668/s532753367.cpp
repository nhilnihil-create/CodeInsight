#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?x:-x;
}
struct Edge{
	int nxt,to;
}e[400050];
int fir[200050],n,cnt;
inline void add(int from,int to){
	e[++cnt].nxt=fir[from];
	fir[from]=cnt;e[cnt].to=to;
}
inline int dfs(int x,int fa){
	int len=0;
	for(int i=fir[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		len=len^(dfs(y,x)+1);
	}
	return len;
}
int main(){
	n=rd();int u,v;
	for(int i=1;i<n;i++){
		u=rd(),v=rd();
		add(u,v);add(v,u);
	}
	if(dfs(1,0)) puts("Alice");
	else puts("Bob");
	return 0;
}