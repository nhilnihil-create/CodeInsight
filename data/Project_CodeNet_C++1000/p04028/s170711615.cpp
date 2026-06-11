#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define INF 1e18

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector < pair<int, int> > vii;
typedef long double ld;
typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll dp[5011][5011], n, m;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> s;
	m=s.length();
	dp[0][0]=1;
	const ll MOD = 1000000007;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(j==0){
				dp[i][j]=2*dp[i-1][j+1]+dp[i-1][j];
			}
			else{
				dp[i][j]=2*dp[i-1][j+1]+dp[i-1][j-1];
			}
			dp[i][j]%=MOD;
			if(dp[i][j]<0) dp[i][j]+=MOD;
		}
	}
	cout << dp[n][m];
	return 0;
}
