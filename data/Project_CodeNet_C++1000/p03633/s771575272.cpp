//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using ld = long double;
using ulint = unsigned long long;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr lint mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#define INF (lint)10000000000000000
#define mod = (int)1000000007;
#pragma endregion
lint n;
vector<lint> d;
void input() {
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	return;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}
ulint lcm(ulint a, ulint b) {
	return a / gcd(a, b) * b;
}
unsigned long long solve() {
	if (n == 1) return d[0];
	unsigned long long ans;
	ans = lcm(d[0], d[1]);
	for (int i = 2; i < n; i++) {
		ans = lcm(ans, d[i]);
	}
	return ans;
}

int main(void) {
	input();
	printf("%llu\n", solve());

	return 0;
}