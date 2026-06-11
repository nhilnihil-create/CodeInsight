#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int n;
string s;
bool veri(char lef, char mid, char rig, char ck){
	int cnt = 0;
	if( lef == rig ) cnt++;
	if( mid == 'S' ) cnt++;
	if( ck == 'o' ) cnt++;
	if( cnt%2 )return true;
	return false;
}
string check(int fi, int se){
	string res;
	if( fi == 0 )res.pb('S'); else res.pb('W');
	if( se == 0 )res.pb('S'); else res.pb('W');
	for(int i=2;i<n;i++){
		if( ( res[i-1] == 'S' && s[i-1] == 'o') || ( res[i-1] == 'W' && s[i-1] == 'x') )res.pb(res[i-2]);
		else res.pb( 'S'+'W'-res[i-2] );
	}
	if(veri(res[n-1],res[0],res[1],s[0]) && veri(res[n-2],res[n-1],res[0],s[n-1]) )return res;
	else return "x";
}
signed main(){
	cin>>n;
	cin>>s;
	string ans;
	ans = check( 0, 0 );
	if( ans != "x" ){
		cout<<ans<<endl;
		return 0;
	}
	ans = check( 0, 1 );
	if( ans != "x" ){
		cout<<ans<<endl;
		return 0;
	}
	ans = check( 1, 0 );
	if( ans != "x" ){
		cout<<ans<<endl;
		return 0;
	}ans = check( 1, 1 );
	if( ans != "x" ){
		cout<<ans<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}