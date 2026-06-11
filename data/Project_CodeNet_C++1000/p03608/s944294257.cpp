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


const int nax = 200, rax = 8;
int dis[nax][nax],dp[1<<rax][rax],a[rax];
int n,m,r;
int solve(int msk,int prv){
	if( msk + 1 == 1 << r )return 0;
	int &ans = dp[msk][prv];
	if( ans != -1 )return ans;
	ans = 1e17;
	for(int i=0;i<r;i++){
		if( msk >> i & 1 )continue;
		ans = min( ans , dis[a[prv]][a[i]] + solve(msk|1<<i,i));
	}
	return ans;
}
int32_t main(){
	IOS
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<nax;i++){
		for(int j=0;j<nax;j++){
			dis[i][j]=1e17;
		}
		dis[i][i]=0;
	}
	cin>>n>>m>>r;
	for(int i=0;i<r;i++){
		cin>>a[i];--a[i];
	}
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;--u,--v;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	int ans=1e17;
	for(int i=0;i<r;i++){
		ans=min(ans,solve(1<<i,i));
	}
	cout<<ans;
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
