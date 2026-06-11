#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
int dp[31][3001];
int main()
{
	int a, b, c, d, e, f, ans_a = 1, ans_b = 0;
	cin >> a >> b >> c >> d >> e >> f;
	dp[0][0] = 1;
	rep(i, 0, 31) {
		rep(i2, 0, f + 1) {
			if (100*i + i2 > f || i*e < i2)continue;
			if (i - a >= 0)dp[i][i2] |= dp[i - a][i2];
			if (i - b >= 0)dp[i][i2] |= dp[i - b][i2];
			if (i2 - c >= 0)dp[i][i2] |= dp[i][i2 - c];
			if (i2 - d >= 0)dp[i][i2] |= dp[i][i2 - d];
			if (dp[i][i2] == 1) {
				//printf("%f\n", 100 * i2 / (double)(100 * i + i2));
				if (i2 * (100 * ans_a + ans_b) >= ans_b * (100 * i + i2)) {
					ans_a = i, ans_b = i2;
				}
			}
		}
	}
	printf("%d %d\n", ans_a * 100 + ans_b, ans_b);
	return 0;
}
