#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
 
#define ll long long
#define pb push_back
#define vi vector<int>
#define sz(a) (int((a).size()))
#define mp make_pair
#define f first
#define s second
#define pii pair<int, int>
 
using namespace std;
 
const int mod = 998244353;
const int inf = (int)2e9;
const ll INF = (ll)2e18;
const int N = 100100;

int n, k;
int a[51];
ll dp[51][51][2501], ans;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][0][0] = 1;
			for (int sum = 0; sum <= 2500; sum++) {
				dp[i][j][sum] = dp[i - 1][j][sum];
				if (sum - a[i] >= 0 && j > 0) {	
					dp[i][j][sum] 
						+= dp[i - 1][j - 1][sum - a[i]];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		ans += dp[n][i][k * i];
	}

	cout << ans << endl;

	return 0;
}