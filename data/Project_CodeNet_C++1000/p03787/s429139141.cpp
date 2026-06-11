#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N,M;
vector<int> edge [100001];
bool vis [100001];

bool dfs(int curr,int p,map<int,int>& color)
{
	vis [curr] = true;
	color [curr] = p;
	int res = true;
	for(const auto& it : edge [curr]){
		if(color.count(it) == 0){
			res &= dfs(it,!p,color);
		}
		else{
			res &= color [it] == !p;
		}
	}
	return res;
}

int main()
{
	scanf("%d%d",&N,&M);
	FOR(i,0,M){
		int u,v;
		scanf("%d%d",&u,&v);
		edge [u].push_back(v);
		edge [v].push_back(u);
	}

	ll x = 0,y = 0,z = 0;
	FOR(i,1,N + 1) if(vis [i] == false){
		map<int,int> color;
		if(dfs(i,0,color)){
			if(color.size() == 1){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			z++;
		}
	}
	ll ans = x * N * 2 - x * x + y * y * 2 + y * z * 2 + z * z;

	printf("%lld\n",ans);

	return 0;
}
