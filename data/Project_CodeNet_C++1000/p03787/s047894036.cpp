#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mms(x) memset(x,0,sizeof(x))
#define mmc(x,y) memcpy(x,y,sizeof(y))
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const int N=100005;

int n,m,a,b,c,col[N];
VI e[N];
ll ans;
bool fl;

void dfs(int x){
	for(int v:e[x])
		if(!col[v])col[v]=3-col[x],dfs(v);else fl&=col[x]+col[v]==3;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u); 
	for(int u=1;u<=n;u++)if(!col[u]){
		col[u]=1;
		if(!e[u].size())a++;else{
			fl=true;dfs(u);
			if(fl)b++;else c++;
		}
	}
	ans=(ll)a*(2*n-a)+(ll)b*b*2+(ll)c*c+(ll)b*c*2;
	printf("%lld\n",ans);
	return 0;
}