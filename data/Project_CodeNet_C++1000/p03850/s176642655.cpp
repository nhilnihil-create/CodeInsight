//#include "IntMod.h"
//typedef IntMod<1000000007> MInt;

//#include "Union_Find.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
//#include <unordered_set>
//#include <unordered_map>
#include <iomanip>
#include <sstream>

using namespace std;
#define REP(i,a,n) for(int i = a; i < n; ++i)
#define REPM(i,n,a) for(int i = n - 1; i >= a; --i)
#define EPS 0.0001
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define INFD 1.0e+308
typedef long long LL;
typedef unsigned long long ULL;

typedef pair<LL, LL> PP;

LL N;
LL A[100001];
char op[100001];
LL dp[3][100001];

int main() {
	cin >> N;
	op[0] = '+';
	REP(i, 0, N) {
		if (i != 0) {
			cin >> op[i];
		}
		cin >> A[i];
	}

	dp[0][0] = A[0];
	dp[1][0] = -INFLL;
	dp[2][0] = -INFLL;
	REP(i, 1, N) {
		if (op[i] == '-') {
			dp[0][i] = max(max(dp[0][i - 1] - A[i], dp[1][i - 1] + A[i]), dp[2][i - 1] - A[i]);
			dp[1][i] = max(max(dp[1][i - 1] + A[i], dp[2][i - 1] - A[i]), dp[0][i - 1] - A[i]);
			dp[2][i] = max(dp[2][i - 1] - A[i], dp[1][i - 1] + A[i]);
		} else {
			dp[0][i] = max(dp[0][i - 1] + A[i], dp[1][i - 1] - A[i]);
			dp[1][i] = max(dp[1][i - 1] - A[i], dp[2][i - 1] + A[i]);
			dp[2][i] = dp[2][i - 1] + A[i];
		}
	}
	cout << max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]) << endl;

	return 0;
}