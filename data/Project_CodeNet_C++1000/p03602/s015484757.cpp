#include <cstdio>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
const int N=305;
int n;
long long dis[N][N],ans;

int check(int x,int y) {
	FOR(i,1,n) {
		if(i==x||i==y) continue;
		if(dis[x][y]==dis[x][i]+dis[i][y]) return 0;
		if(dis[x][y]>dis[x][i]+dis[i][y]) return -1;
	}
	return 1;
}
int main() {
	scanf("%d",&n);
	FOR(i,1,n) FOR(j,1,n) scanf("%lld",&dis[i][j]);
	FOR(i,1,n) FOR(j,i+1,n) {
		int opt=check(i,j);
		if(opt<0) return puts("-1"),0;
		if(opt>0) ans+=dis[i][j];
	}
	printf("%lld\n",ans);
	return 0;
}