#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

int x[50];
ll dp[51][50][2501] = { 0 };

int main()
{
	int N, A, total = 0;
	ll ans = 0;

	cin >> N >> A;
	rep(i, N) {
		cin >> x[i];
		total += x[i];
	}

	repc(num, 1, N) {
		repc(until, num - 1, N - 1) {
			if (until == 0) {
				dp[num][until][x[until]] = 1;
				continue;
			}

			repc(sum, 1, total) {
				if (num == 1) {
					dp[num][until][sum] += dp[num][until - 1][sum];

					if (x[until] == sum)
					dp[num][until][x[until]]++;
					continue;
				}

				dp[num][until][sum] += dp[num][until - 1][sum];
				if (sum - x[until] > 0) dp[num][until][sum] += dp[num - 1][until - 1][sum - x[until]];
			}
		}
	}

	repc(num, 1, N) {
		int sum = A * num;
		ans += dp[num][N - 1][sum];
	}

	cout << ans << endl;

	return 0;
}