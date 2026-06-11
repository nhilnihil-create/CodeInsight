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


int l = 1e18;
string ans,s;
int nxt[200010][26],dp[200010],tmp[26];
int n;

int solve(int i){
	if( i == n ) return 1;
	int & ans = dp[i];
	if( ans != -1 )return ans;
	ans = 1e18;
	for(int c = 0 ; c < 26; c++ ){
		ans = min( ans , 1+solve(nxt[i][c]) );
	}
	return ans;
}
int32_t main(){
	IOS
	cin >> s;
	n = s.length();
	for(int i=0;i<26;i++){
		tmp[i]=n;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<26;j++){
			nxt[i][j]=tmp[j];
		}
		tmp[s[i]-'a']=i;
	}
	memset(dp,-1,sizeof(dp));
	
	int j = 0;
	for(int i = 0; i < 26; i++ ){
		if( solve(tmp[i]) < solve(tmp[j]) ){
			j = i;
		}
	}
	int N =  solve(tmp[j]);
	int i =  tmp[j];
	while( N-- ){
		cout << ( char( j + 'a' ) );
		int newj = 0;
		for(int c = 0 ; c < 26; c++ ){
			if( solve(nxt[i][c]) < solve(nxt[i][newj]) ){
			   newj = c;
		    }
		}
		j = newj;
		i = nxt[i][j];
	}
	
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
