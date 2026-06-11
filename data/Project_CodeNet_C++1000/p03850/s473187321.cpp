#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i, n) for ( int i = 0 ; i < (n); i++ )
#define All(v) v.begin(), v.end()

typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

signed main() {
	int N;
	int A[100001];
	char op[100001];
	int dp[100001][3];	

	fill_n(*dp, 100001*3, -INF);
	
	cin >> N;
	cin >> A[0];
	dp[0][0] = A[0];

	for ( int i = 1; i < N; i++ ) cin >> op[i] >> A[i];
	
	for ( int i = 1; i < N; i++ ) {
		if ( op[i] == '+' ) {
			dp[i][0] = dp[i-1][0]+A[i];
			dp[i][1] = dp[i-1][1]-A[i];
			dp[i][2] = dp[i-1][2]+A[i];
		} else {
			//open
			dp[i][1] = max(dp[i-1][0], dp[i-1][2])-A[i];
			dp[i][0] = dp[i][2] = dp[i-1][1]+A[i];			
		}

		//close
		dp[i][1] = max(dp[i][1], dp[i][2]);
		dp[i][0] = max(dp[i][0], dp[i][1]);
	}

	cout << *max_element(dp[N-1], dp[N-1]+3) << endl;

	return 0;
}
