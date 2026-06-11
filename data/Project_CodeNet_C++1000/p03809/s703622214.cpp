#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
struct edge{int x, y, next;}a[N*2];
int n, w[N], x, y, l, p[N], ff, f[N], du[N], root;
inline void add(int x, int y){a[++l].x=x; a[l].y=y; a[l].next=p[x]; p[x]=l;}
inline void dp(int x, int fa){
	if(!a[p[x]].next){f[x]=w[x]; return;}
	for(int i=p[x]; i; i=a[i].next)if(fa!=a[i].y)dp(a[i].y, x);
	if(!ff)return;
	int mx=0; ll sum=0, R, s;
	for(int i=p[x]; i; i=a[i].next)if(fa!=a[i].y){mx=max(mx, f[a[i].y]); sum+=f[a[i].y];}
	if(mx*2>=sum)R=sum-mx; else R=sum>>1;
	s=sum-w[x];
	if(s<0||s>R){ff=0; return;}
	f[x]=sum-s*2;
}
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)scanf("%d", &w[i]);
	l=0; memset(p, 0, sizeof(p)); memset(du, 0, sizeof(du));
	for(int i=1; i<=n-1; i++){scanf("%d%d", &x, &y); add(x, y); add(y, x); du[x]++; du[y]++;}
	if(n==2){if(w[1]==w[2])printf("YES"); else printf("NO"); return 0;}
	for(int i=1; i<=n; i++)if(du[i]>=2)root=i;
	ff=1; dp(root, 0); if(ff&&f[root])ff=0;
	if(ff)printf("YES"); else printf("NO");
	return 0;
}