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
int n,m,I,P,Q,co[N];
vector<int> e[N];
bool check(int x,int fa,int c){
	co[x]=c;
	bool ans=1;
	for (auto i:e[x]){
		if (i==fa) continue;
		if (!co[i]) ans&=check(i,x,-c);
		else ans&=(c!=co[i]);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n){
		if (co[i]) continue;
		if (e[i].size()==0) I++;
		else if (check(i,0,1)) Q++;
		else P++;
	}
	printf("%lld\n",1ll*I*I+2ll*I*(n-I)+1ll*P*P+2LL*P*Q+2ll*Q*Q);
}