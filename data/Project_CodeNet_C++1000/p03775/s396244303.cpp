#include <bits/stdc++.h>

#define rep(i,n) for(int i=1;i<n;i++)

using namespace std;


map<long long, int> dp;

int solve(double X) {
	if (dp[X] > 0)return dp[X];

	int ret = log10(X) + 1;

	dp[X] = ret;

	return ret;
}




int main(void)
{
	long long N, A, B;
	int ans = INT_MAX, tmp;

	cin >> N;

	rep(A, sqrt(N) + 1) {
		if (N % A != 0)continue;

		B = N / A;
		tmp = max(solve(A), solve(B));
		if (ans > tmp) {
			ans = tmp;
		}
	}
	cout << ans << endl;

	return 0;
}
