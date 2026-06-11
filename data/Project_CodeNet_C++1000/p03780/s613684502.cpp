#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

int N, K;
int a[5009];
bool dp[5009][5009]; // dp[i][j] : 1からi番目までのカードのみでjがつくれるかどうか

bool need(int m) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) dp[i][j] = false;
	}

	dp[0][0] = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {

			if (dp[i][j]) {
				dp[i + 1][j] = true;
				// a[m]は使ってはいけない
				if (i+1 != m && j + a[i + 1] < K) dp[i + 1][j + a[i + 1]] = true;
			}
		}
	}

	// dp[N][K-a[n]]～dp[N][K-1]がすべてfalseなら不要
	bool flag = false;
	for (int i = max(0,K - a[m]); i < K && !flag; i++) {
		if (dp[N][i]) flag = true;
	}

	return flag;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> a[i];
	sort(a + 1, a + N + 1);

	// right以上のものは必要
	// left以下のものは不要
	int left = 0;
	int right = N + 1;

	while (left != right - 1) {
		int mid = (left + right) / 2;
		if (need(mid)) right = mid;
		else left = mid;
	}

	cout << left << endl;

	return 0;
}