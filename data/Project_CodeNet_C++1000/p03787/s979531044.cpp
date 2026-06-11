/// kAAzuki Hoshino
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 100005;

int vis[MAXN], c[MAXN], n, m;
vector<int> adj[MAXN];

bool dfs(int s, int color){
	if(c[s]){
		return c[s] == color;
	}
	c[s] = color;
	bool res = true;
	for(auto t:adj[s]){
		if(!dfs(t, 3-color)){
			res = false;
		}
	}
	return res;
}

signed main(){
IOS;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int isolated=0,bipartite=0,other=0;
	for(int i=1;i<=n;i++){
		if(!c[i]){
			if(adj[i].size()){
				if(dfs(i, 1)){
					bipartite++;
				}
				else other++;
			}
			else {
				isolated++;
				c[i]=1;
			}
		}
	}
	//cerr << isolated << " " << bipartite << " " << other << endl;
	int ans = isolated*isolated + 2*isolated*(n-isolated) + 2*bipartite*bipartite + other*other + 2*other*bipartite;
	cout << ans << endl;

return 0;
}
///....
