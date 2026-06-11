/********************    I am only one, but still I am one.    **************************************/
/**************    I cannot do everything, but still I can do something.    *************************/
/***   And because I cannot do everything I will not refuse to do the something that I can do.    ***/
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

struct box{
	int v,d,c;
};
const int maxn = 1e5+5;
vector<int>g[maxn],lst(maxn),clr(maxn);
int vis[maxn][11];
vector<box>q(maxn);
int n,m,t;
void dfs(int u,int d,int c){
	if( vis[u][d] )return; // O( 10 * ( n+m) )
	vis[u][d]=1;
	if( !clr[u] ){
		clr[u] = c;
	}
	if(d == 0 )return;
	for(auto v:g[u]){
		dfs(v,d-1,c);
	}
}
int32_t main(){
	IOS
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>q[i].v>>q[i].d>>q[i].c;
	}
	reverse(q.begin()+1,q.begin()+t+1);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=t;i++){
		dfs(q[i].v,q[i].d,q[i].c);
	}
	for(int i=1;i<=n;i++){
		cout << clr[i] << endl;
	}
	
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
