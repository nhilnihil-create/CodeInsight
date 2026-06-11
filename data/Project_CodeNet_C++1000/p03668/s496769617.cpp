#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n;
vector<int> edge[100010];
int par[100010];

int dfs(int x){
	int ret = 0;
	for(int y:edge[x]){
		if(par[x]==y) continue;
		par[y]=x;
		ret ^= (1+dfs(y));
	}
	return ret;
}

int main()
{
	read(n);
	for(int i=1; i<n; ++i){
		int a, b;
		read(a, b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	puts(dfs(1)?"Alice":"Bob");
	return 0;
}
