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
int c[9][9];
map<ll, int> prime_factor(ll num) {
	map<ll, int> mp;
	ll k = (ll)sqrt(num);
	mp[1]++;
	rep(i, 2, k + 1) {
		while (num % i == 0) {
			num /= i;
			mp[i]++;
		}
	}
	if (num != 1)mp[num]++;
	return mp;
}
//mpの各要素は(first:素因数, second:指数)
//mp.size()にすれば素因数が何種類かを取得できる
//1が含まれることに注意
const ll mod = 1000000007;
int main() {
	int n, d = 0, c = 0;
	char str[101];
	scanf("%d", &n);
	scanf("%s", str);
	rep(i, 0, n) {
		if (str[i] == '(')d++;
		else d--;
		c = min(d, c);
	}
	rep(i, c, 0)printf("(");
	printf(str);
	rep(i, 0, d - c)printf(")");
	puts("");
	return 0;
}
