#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <list>

using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define rrep(i,a) for(int i = a; i >= 0; i--)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

/*
// 最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll x, y;
	cin >> x >> y;
	
	if (x <= 1 && y <= 1) {
		cout << "Brown" << endl;
		return 0;
	}

	// |x - y| <= 1となるならBrownのかち

	if (abs(x - y) <= 1) {
		cout << "Brown" << endl;
	}
	else {
		cout << "Alice" << endl;
	}
	
	return 0;
}
