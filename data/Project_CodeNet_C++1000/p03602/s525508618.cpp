#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
#define Rep(i,a,b) for (int (i)=(a);(i)<(b);(i)++)
#define REP(i,a,b) for (int (i)=(a);(i)>=(b);(i)--)
#define reg(i,x)   for (int (i)=head[x];(i);i=e[i].next)
#define lowbit(x) ((x)&(-(x)))
#define ls ((x)<<1)
#define rs ((x)<<1|1)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define P pair<int,int>
const int N = 100010 ;
const int inf = 1e18 ; 
const int MOD = 1e9+7 ;

struct node {
	int x,y,dis ;
}e[100010];

bool cmp(node a,node b){
	return a.dis<b.dis ;
}

int n,m,ans ;
int dis[310][310] ;

void floyd(int k){
	rep(i,1,n) rep(j,1,n) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]) ;
}

void print(){
	printf("-1\n") ;
	exit(0) ;
}

signed main(){
	ios::sync_with_stdio(false) ;
	scanf("%lld",&n) ;
	rep(i,1,n) {
		rep(j,1,n) dis[i][j]=inf ;
		dis[i][i]=0 ;
	}
	rep(i,1,n) rep(j,1,n) {
		int x ;
		scanf("%lld",&x) ;
		if (j>i) {
			e[++m].x=i;
			e[m].y=j ;
			e[m].dis=x ;
		}
	}
	sort(e+1,e+m+1,cmp) ;//把边排序，选最小的构成图 
//	for (int i=1;i<=m;i++) cout<<e[i].x<<" "<<e[i].y<<" "<<e[i].dis<<endl ;
	for (int i=1;i<=m;i++){ //选较小的边，更新 
		int from=e[i].x,to=e[i].y,dist=e[i].dis ;
//		cout<<dis[from][to]<<endl ;
		if (dis[from][to]<dist) print() ;
		else if (dis[from][to]>dist){
			dis[from][to]=dis[to][from]=dist ;
			ans+=dist ;
			floyd(from);floyd(to) ;
		}
	}
	printf("%lld\n",ans) ; 
}
/*
3
0 1 3
1 0 1
3 1 0
*/
