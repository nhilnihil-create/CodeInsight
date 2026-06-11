#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>


#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

lli mod197 = 1000000007LL;
lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

lli N, K;
lli a[5000 + 10];

lli dp[5000 + 10][5000 + 10];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	//ここそのためにソートしているのか
	//＜の関係にしている
	sort(a, a + N);

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			dp[i + 1][j] += dp[i][j];
			if (j + a[i] < K) {
				dp[i + 1][j + a[i]] += dp[i][j];
			}
		}
	}

	int ans = N;
	for (int i = 0; i < N; i++) {

		lli dplast[5000 + 10] = {};
		for (int j = 0; j < K; j++)dplast[j] = dp[N][j];
		for (int j = 0; j < K; j++) {
			//dpを一回さし戻す
			if (j + a[i] < K)dplast[j + a[i]] -= dplast[j];
			//ここが-にならないのはなんで
			if (j >= K - a[i] && dplast[j]) {
				ans--;
				break;
			}
		}
	}

	COUT(ans);
	return 0;
}