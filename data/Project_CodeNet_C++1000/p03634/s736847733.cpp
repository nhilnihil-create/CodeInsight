#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;


const int maxn = 1e5+10, lgN = 20;
vector<vector<pair<int,int>>>g(maxn);
vector<int> tin(maxn);
vector<int> tout(maxn);
vector<vector<int>>par(maxn,vector<int>(lgN+1));
vector<vector<int>>dis(maxn,vector<int>(lgN+1));
int timer = 0, n;

void dfs(int u=1,int p=0,int w=0){
	tin[u]=++timer;
	par[u][0]=p;
	dis[u][0]=w;
	for(int i=1;i<=lgN;i++){
		par[u][i]=par[ par[u][i-1] ][i-1];
		dis[u][i]=dis[ par[u][i-1] ][i-1]+dis[u][i-1];
	}
	for(auto it:g[u]){
		int v=it.first;
		int w=it.second;
		if( v!= p){
			dfs(v,u,w);
		}
	}
	tout[u]=++timer;
}

int isAncestor(int u,int v){
	return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int lca(int u,int v){
	if( isAncestor(u,v) )return u;
	if( isAncestor(v,u) )return v;
	for(int i=lgN;i>=0;i--){
		if( par[u][i] && !isAncestor(par[u][i],v)){
			u=par[u][i];
		}
	}
	return par[u][0];
}

int DisQuery(int u,int v){
	int l = lca(u,v);
	int d = 0;
	auto shiftup =[&](int u){
		if( u!=l ){
			for(int i=lgN;i>=0;i--){
				if( par[u][i] && !isAncestor(par[u][i],l)){
					d+=dis[u][i];
					u=par[u][i];
				}
			}
			d+=dis[u][0];
		}
	};
	shiftup(u);
	shiftup(v);
	return d;
}

int32_t main(){
	IOS
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0,0);
	int q,k;cin>>q>>k;
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<DisQuery(u,k)+DisQuery(v,k)<<endl;
	}
	

	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
