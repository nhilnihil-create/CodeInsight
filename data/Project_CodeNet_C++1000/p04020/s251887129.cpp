#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	vector<LLONG> as(N); REP(i, N) cin >> as[i];
	LLONG ans = 0;
	// 貪欲にペアを作っていく
	for (int i = 0; i < N - 1; ++i)
	{
		// i 同士のペア
		ans += as[i] / 2;
		as[i] %= 2;
		// i + 1 とのペア
		LLONG num = min(as[i], as[i + 1]);
		ans += num;
		as[i + 1] -= num;
	}
	// 残った as[N - 1] でペアを作る
	ans += as.back() / 2;
	cout << ans << endl;
}