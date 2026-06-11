#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int xx=0,ff=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){xx=xx*10+ch-'0';ch=getchar();}
	return xx*ff;
}
const int maxn=100010;
int N,M,Q,lin[maxn],len;
struct edge{
	int y,next;
}e[maxn*2];
inline void insert(int xx,int yy){
	e[++len].next=lin[xx];
	lin[xx]=len;
	e[len].y=yy;
}
inline void ins(int xx,int yy){
	insert(xx,yy);
	insert(yy,xx);
}
int col[maxn],v[maxn],d[maxn],c[maxn];
bool opt[maxn][11];
void dfs(int x,int d,int c){
	if(opt[x][d])
		return;
	for(int i=d;i>=0;i--)
		opt[x][i]=1;
	if(!col[x])
		col[x]=c;
	if(!d)return;
	for(int i=lin[x];i;i=e[i].next)
		dfs(e[i].y,d-1,c);
}
int main(){
	//freopen("in.txt","r",stdin);
	N=read(),M=read();
	for(int i=1;i<=M;i++)
		ins(read(),read());
	Q=read();
	for(int i=1;i<=Q;i++)
		v[i]=read(),d[i]=read(),c[i]=read();
	for(int i=Q;i>=1;i--)
		dfs(v[i],d[i],c[i]);
	for(int i=1;i<=N;i++)
		printf("%d\n",col[i]);
	return 0;
} 

