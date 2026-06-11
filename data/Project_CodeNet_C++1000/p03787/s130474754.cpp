#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,m;
vector<int> g[100005];
int c[100005];

bool dfs(int x){
	bool r=true;
	for(auto y:g[x]){
		if(c[y]==c[x])r=false;
		if(c[y]<0){
			c[y]=1-c[x];
			if(!dfs(y))r=false;
		}
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	memset(c,-1,sizeof(c));
	int na=0,nb=0,nc=0;
	fore(x,0,n){
		if(c[x]>=0)continue;
		if(!g[x].size())na++;
		else {
			c[x]=0;
			if(dfs(x))nb++;
			else nc++;
		}
	}
	ll r=2*nb+na+nc;
	r+=1LL*nb*(2*(nb-1)+nc);
	r+=1LL*nc*(nb+nc-1);
	r+=2LL*na*(n-1)-1LL*na*(na-1);
	printf("%lld\n",r);
	return 0;
}