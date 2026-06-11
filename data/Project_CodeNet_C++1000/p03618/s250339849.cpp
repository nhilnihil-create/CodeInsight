#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	string A; cin >> A;
	int N = (int)A.size();
	vector<ll> dp(N, 0);
	dp[0] = 1;
	vector<int> cnt(26, 0);
	cnt[A[0] - 'a']++;
	for (int i = 1; i < N; i++) {
		int x = A[i] - 'a';
		dp[i] = dp[i - 1] + (i - cnt[x]);
		cnt[x]++;
	}
	cout << dp[N - 1] << endl;

	return 0;
}
