#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define ll long long
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static int buf[20],len; len=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)buf[len++]=x%10;
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]+'0');
}
inline void writeln(ll x){write(x); putchar('\n');}
inline void writesp(ll x){write(x); putchar(' ');}
struct edge{
	int to,nxt;
}e[2*maxn];
int fir[maxn],sg[maxn];
int n,tot;
inline void add_edge(int x,int y){e[tot].to=y; e[tot].nxt=fir[x]; fir[x]=tot++;}
void dfs(int now,int fa)
{
	sg[now]=0;
	for(int i=fir[now];~i;i=e[i].nxt)
		if(e[i].to!=fa){
			dfs(e[i].to,now);
			sg[now]^=(sg[e[i].to]+1);
		}
}
int main()
{
	n=read();
	memset(fir,255,sizeof(fir)); tot=0;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add_edge(x,y); add_edge(y,x);
	}
	dfs(1,-1);
	if(sg[1])puts("Alice");
	else puts("Bob");
	return 0;
}