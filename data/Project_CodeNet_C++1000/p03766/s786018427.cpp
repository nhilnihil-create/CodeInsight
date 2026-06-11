#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll dp[1000050];
ll sum[1000050];

int main() {
	ll N, i;
	scanf("%lld", &N);

	dp[0] = 1, dp[1] = N, dp[2] = N*N%MOD;
	sum[0] = 0, sum[1] = dp[1], sum[2] = sum[1] + dp[2];

	for (i = 3; i <= N; i++) {
		dp[i] = dp[i - 1];
		dp[i] = (dp[i] + (N - 1)*(N - 1)) % MOD;
		dp[i] = (dp[i] + N + 2 - i) % MOD;
		dp[i] = (dp[i] + sum[i - 3]) % MOD;
		sum[i] = sum[i - 1] + dp[i];
	}
	return !printf("%lld\n", dp[N]);
}