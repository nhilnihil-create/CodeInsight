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
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1 << 30
#define MAX 1000000000

ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }

int main() {
	int N, M, x, y;
	scanf("%d%d", &N, &M);
	vector<int> c(N, 1), f(N, 0);
	f[0] = 1;
	rep(i, 0, M) {
		scanf("%d%d", &x, &y);
		x--, y--;
		f[y] |= f[x];
		c[y]++, c[x]--;
		if (c[x] == 0)f[x] = 0;
	}
	int ans = 0;
	rep(i, 0, N) {
		if (f[i])ans++;
	}
	printf("%d\n", ans);
	return 0;
}