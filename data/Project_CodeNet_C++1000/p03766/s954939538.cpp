#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <fstream>
#include <functional>
#include <bitset>
#include <stack>
#include <set>
#include <climits>
#define MAX_N 2000
#define LOG 21
#define PI 3.141592653589
#define EPS 1e-6
#define MOD 1000000007
#define YJSNPI 810
#define INF (1 << 30)
#define ADD(a, b) a = (a + (ll)b) % MOD
#define MUL(a, b) a = (a * (ll)b) % MOD
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define RER(i, a, b) for(int i = a - 1; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;

void debug() {cout << endl; }

template<class FIRST, class... REST>
void debug(FIRST arg, REST... rest) { cout << arg << " "; debug(rest...); }

int N;
ll dp[1000010];
ll dp2[1000010];

int main() {
	scanf("%d", &N);
	dp[0] = dp2[0] = 1;
	for(int i = 1; i <= N - 1; i++) {
		if(i >= 3) dp[i] = dp[i - 1] + dp2[i - 3];
		else dp[i] = dp[i - 1];
		dp2[i] = dp[i] + dp2[i - 1];
		dp[i] %= MOD;
		dp2[i] %= MOD;
	}
	ll res = 0;
	for(int i = 0; i < N - 1; i++) {
		//debug(i, res);
		res += dp[i] * (N - 1) % MOD * (N - 1) % MOD; res %= MOD;
		if(N - i == 2) res += dp[i] * (i + 1) % MOD;
		else res += dp[i] * (i + 2) % MOD;
		res %= MOD;
	}
	res += dp[N - 1] * N % MOD;
	res %= MOD;
	printf("%lld\n", res);
}

