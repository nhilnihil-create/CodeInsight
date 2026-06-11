#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}

vector<int>g[100010];
vector<int>level(100010,-1);
vector<int>col(100010,0);
vector<int>c(100010),d(100010),v(100010);

void dfs(int now,int x,int nowcol){
	if(level[now]>=x)return;
	if(col[now]==0)col[now] = nowcol;
	level[now] = x;
	for(auto e:g[now]){
		if(x)dfs(e,x-1,nowcol);
	}
}

signed main(){
	int N,M,Q;
	cin>>N>>M;
	REP(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin>>Q;
	REP(i,Q){
		cin>>v[i]>>d[i]>>c[i];
		v[i]--;
	}
	RREP(i,Q){
		dfs(v[i],d[i],c[i]);
	}
	REP(i,N){
		cout<<col[i]<<endl;
	}
}