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
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const ll mod = 1000000007;
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
int main() {
	int ans, c;
	string x;
	bool f = 1, ok, dame;
	cin >> x;
	ans = x.size();
	if (x.back() == '\n')x.pop_back();
	rep(i, 0, x.size()) {
		if (x[0] != x[i])break;
		else if (i == x.size() - 1) {
			puts("0");
			return 0;
		}
	}
	rep(i, 'a', 'z' + 1) {
		string a, b;
		a += x;
		b += x;
		c = 0;
		f = 1;
		while (1) {
			auto &t = f ? a : b, &t2 = f ? b : a;
			ok = true;
			dame = true;
			rep(i2, 0, t.size() - 1 - c) {
				if (t[i2] == (char)i || t[i2 + 1] == (char)i)t2[i2] = i, dame = false;
				else t2[i2] = 'A', ok = false;
			}
			f = !f;
			c++;
			//cout << (char)i << ':' << t2 << endl;
			if (dame)c = ans;
			if (ok || dame)break;
		}
		ans = min(ans, c);
	}
	printf("%d\n", ans);
	return 0;
}
