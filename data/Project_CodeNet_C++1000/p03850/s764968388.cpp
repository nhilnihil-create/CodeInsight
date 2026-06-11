//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

vector<int> nw;
int n, a[N], dp[N][4];
bool What[N];

int POW(int x){
	return (x % 2 ? -1 : 1);
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for( int i = 1; i <= n; i++){
		cin >> a[i];
		if (i != n){
			char c;
			cin >> c;
			if (c == '-') What[i] = 1;
		}
	}
	for( int i = 0; i < N; i++) for (int j = 0; j < 3; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	//cout << POW(1) << ' ' << POW(2) << '\n';
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 2; j++){
			if (What[i - 1]){
				dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + POW(j + 1) * a[i]);
				if (j != 0){
					dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j] + POW(j + 1) * a[i]);
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + POW(j + 1) * a[i]);
			}else{
				//cout << i << '\n';
				if (j != 0) dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j] + POW(j) * a[i]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + POW(j) * a[i]);
			}
		}
	}
	//cout << dp[1][0] << ' ' << dp[2][1] << ' ' << dp[3][1] << ' ' << dp[4][0] << '\n';
	ll ans = max(dp[n][0], max(dp[n][2], dp[n][1]));
	cout << ans;









	return 0;
}
