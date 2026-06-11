#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
struct edge{int x, y, next;}a[N*2];
int n, l, p[N], sg[N], x, y, ans;
inline void add(int x, int y){a[++l].x=x; a[l].y=y; a[l].next=p[x]; p[x]=l;}
inline void dfs(int x, int fa){
	sg[x]=0;
	for(int i=p[x]; i; i=a[i].next)if(fa!=a[i].y){dfs(a[i].y, x); sg[x]^=sg[a[i].y];}
	sg[x]++;
}
int main(){
	scanf("%d", &n);
	l=0; memset(p, 0, sizeof(p));
	for(int i=1; i<=n-1; i++){scanf("%d%d", &x, &y); add(x, y); add(y, x);}
	ans=0;
	for(int i=p[1]; i; i=a[i].next){dfs(a[i].y, 1); ans^=sg[a[i].y];}
	if(ans)printf("Alice"); else printf("Bob");
	return 0;
}