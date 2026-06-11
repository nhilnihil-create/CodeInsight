#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; ++i)

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

const int GCM(const int a, const int b)
{
	if (b == 0) return a;
	if (a < b) return GCM(b, a);
	return GCM(b, a % b);
}

int main()
{
	int N, K; cin >> N >> K;
	vector<int> balls(N); REP(i, N) cin >> balls[i];
	int max = *max_element(balls.begin(), balls.end());
	if (max < K)
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		int gcm = balls[0];
		REP(i, N) gcm = GCM(gcm, balls[i]);
		cout << (K % gcm == 0 ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}
}