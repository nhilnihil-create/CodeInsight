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
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
int main() {
	int H, W;
	char c;
	cin >> H >> W;
	map<char, int> mp;
	rep(i, 0, H * W) {
		c = getc(stdin);
		if (c == '\n')i--;
		else mp[c]++;
	}
	int a[4] = { 0 };
	for (auto m : mp) {
		a[m.second % 4]++;
	}
	if (W % 2 && H % 2) {
		if (a[1])a[1]--;
		else if (a[3] == 1) {
			a[2]++;
			a[3]--;
		}
	}
	if (a[1] + a[3]) {
		puts("No");
		return 0;
	}
	int k = 0;
	if (W % 2)k += H / 2;
	if (H % 2)k += W / 2;
	puts(a[2] > k ? "No" : "Yes");
	return 0;
}
