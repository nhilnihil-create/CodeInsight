#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<long long,long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,j,k)  for(register int i=(int)(j);i<=(int)(k);i++)
#define rrep(i,j,k) for(register int i=(int)(j);i>=(int)(k);i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)

ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int maxn=100100;
int n,k,ans,a[maxn];
vector<int> G[maxn];

int dfs(int u){
	int nw=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		nw=max(nw,dfs(v));
	}
	nw++;
	if(nw==k && a[u]!=1) ans++,nw=0;
	return nw;
}

void work(){
	n=read(),k=read();
	rep(i,1,n){
		int x=read();
		a[i]=x;
		if(i==1){
			if(x!=1) ans++;
			a[i]=1;
		}
		else G[x].pb(i);
	}
	dfs(1);
	cout<<ans<<endl;
}

int main(){
	#ifdef LZT
		freopen("in","r",stdin);
	#endif
	
	work();
	
	#ifdef LZT
		Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
	#endif
}
