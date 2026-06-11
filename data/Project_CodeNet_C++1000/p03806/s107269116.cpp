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

const int maxn = 40;
int n,ma,mb;
int dp[maxn][maxn*10+1][maxn*10+1],a[maxn],b[maxn],c[maxn];
int solve(int i,int x,int y){
	if( i == n )return  x && x * mb == y * ma ? 0 : 1e18;
	int & ans = dp[i][x][y];
	if( ans != -1 )return ans;
	ans = 1e18;
	ans = min( ans , solve(i+1,x,y) );
	ans = min( ans , c[i] + solve(i+1,x+a[i],y+b[i]) );
	return ans;
}
int32_t main(){
	IOS
	memset(dp,-1,sizeof(dp));
	cin>>n>>ma>>mb;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans = solve(0,0,0);
	cout << ( ans < 1e18 ? ans : -1 ) << endl;
 }
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
