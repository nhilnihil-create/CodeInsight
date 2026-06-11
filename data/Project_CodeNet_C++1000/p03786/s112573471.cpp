#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; cin >> N;
	vector<LLONG> as(N); REP(i, N) cin >> as[i];
	sort(as.begin(), as.end());
	LLONG sum = 0;
	int ans = N;
	REP(i, N - 1)
	{
		sum += as[i];
		if (sum * 2 < as[i + 1])
		{
			ans = N - (i + 1);
		}
	}
	cout << ans << endl;
}