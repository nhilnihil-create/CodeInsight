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
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
int main() {
	int N, c = 0;
	cin >> N;
	vector<ll> a(N), b(N);
	rep(i, 0, N)cin >> a[i];
	sort(all(a));
	b[0] = a[0];
	rep(i, 1, N)b[i] = b[i - 1] + a[i];
	if (b[0] * 2 >= a[1])c++;
	rep(i, 0, N - 1) {
		if (b[i] * 2 < a[i + 1])c = 0;
		c++;
	}
	printf("%d\n", c);
	return 0;
}
