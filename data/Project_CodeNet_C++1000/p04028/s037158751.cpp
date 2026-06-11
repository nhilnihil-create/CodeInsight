//coded by not_surrender

#include <bits/stdc++.h>

#define MAXN 5010
#define MOD 1000000007
#define mid ((a+b)/2)
#define L (nod*2)
#define R (nod*2+1)
#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef vector <int> vi;

ll N, dp[MAXN][MAXN];

string S;

int main(){

	//~ freopen( "a.txt", "r", stdin );
	
	ios_base::sync_with_stdio( false );
	cin.tie( NULL ), cout.tie( NULL );
	
	cin >> N >> S;
	
	dp[0][0] = 1;
	for ( int i = 0; i < N; ++i ){
		dp[i+1][0] = (dp[i+1][0]+dp[i][0])%MOD;
		for ( int j = 0; j <= N; ++j ){
			if ( j )
				dp[i+1][j-1] = (dp[i+1][j-1]+2*dp[i][j])%MOD;
			dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;
		}
	}
	
	cout << dp[N][S.size()] << '\n';

return 0;	
}
