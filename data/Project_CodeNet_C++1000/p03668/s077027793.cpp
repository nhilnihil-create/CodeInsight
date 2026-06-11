#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

int N;
vector<int>G[100005];
int dfs(int x,int p){
	int res=0;
	for(int i:G[x])if(i!=p){
		res^=dfs(i,x)+1;
	}
	return res;
}
signed main(){
	cin>>N;
	rep(i,N-1){
		int a,b;cin>>a>>b;a--;b--;
		G[a].pb(b);G[b].pb(a);
	}
	if(dfs(0,0))cout<<"Alice\n";
	else cout<<"Bob\n";
}
