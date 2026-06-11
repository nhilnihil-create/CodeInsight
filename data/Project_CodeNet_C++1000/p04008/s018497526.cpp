#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=100005;
vector<int> e[N];
int dis[N],dep[N],n,k,ans;
void dfs(int x,int fa){
	dis[x]=dep[x];
	for (int i:e[x]){
		dep[i]=dep[x]+1; dfs(i,x);
		dis[x]=max(dis[x],dis[i]);
	}
	if (fa!=1&&x!=1&&dis[x]-dep[x]==k-1)
		++ans,dis[x]=0;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n){
		int x; scanf("%d",&x);
		if (i==1) ans+=(x!=1);
		else e[x].PB(i);
	}
	dfs(1,0);
	printf("%d",ans);
}