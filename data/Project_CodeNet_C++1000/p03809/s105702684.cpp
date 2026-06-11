#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1000100,P=1e9+7;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
int n,a[N],h[N],ne[N],to[N],du[N],L,flag=1;
inline void addl(int x,int y){
	ne[++L]=h[x];h[x]=L;to[L]=y;du[x]++;
	ne[++L]=h[y];h[y]=L;to[L]=x;du[y]++;
}
int dfs(int x,int fa){
	if(du[x]==1)return a[x];
	int re=a[x]+a[x],k,s;
	for(k=h[x];k;k=ne[k])
	if(to[k]!=fa){
		s=dfs(to[k],x);
		if(s>a[x])flag=0;
		re-=s;
	}if(re>a[x]||re<0)flag=0;
	return re;
}
int main(){
	//freopen("1.out","w",stdout);
	int i;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	if(n==2){flag=(a[1]==a[2]);}
	for(i=1;i<n;i++)addl(read(),read());
	for(i=1;i<=n;i++)if(du[i]>1)
	{if(dfs(i,0)>0)flag=0;break;}
	puts(flag?"YES":"NO");
	return 0;
}