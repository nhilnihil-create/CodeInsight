#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define M 400010
#define ll long long
using namespace std;
struct edge{int x, y, next;}a[M];
int n, m, p[N], l, x, y, flag[N], sn, ff, s1, s2, s3, size1, size2, size3, def[N];
ll ans;
inline void add(int x, int y){a[++l].x=x; a[l].y=y; a[l].next=p[x]; p[x]=l;}
inline void dfs(int x, int fa){
	flag[x]=1; sn++;
	for(int i=p[x]; i; i=a[i].next)if(i!=(fa^1)){
		if(!flag[a[i].y]){def[a[i].y]=def[x]+1; dfs(a[i].y, i);}
		else if(!((def[x]-def[a[i].y])&1))ff=0;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	l=1; memset(p, 0, sizeof(p));
	for(int i=1; i<=m; i++){scanf("%d%d", &x, &y); add(x, y); add(y, x);}
	memset(flag, 0, sizeof(flag));
	for(int i=1; i<=n; i++)if(!flag[i]){
		sn=0; ff=1; def[i]=1; dfs(i, 0);
		if(sn==1){s1++; size1+=sn;}
		else if(ff){s2++; size2+=sn;}
		else{s3++; size3+=sn;}
	}
	ans=(ll)s1*s1+(ll)2*s2*s2+(ll)s3*s3+(ll)2*s1*size2+(ll)2*s1*size3+(ll)2*s2*s3;
	printf("%lld", ans);
	return 0;
}