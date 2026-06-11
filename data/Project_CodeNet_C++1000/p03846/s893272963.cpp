// type a
//a...いけそう
//b...自信がない
//c...お試し
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
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
#include <array>
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
#define mod (lint)1000000007
#pragma endregion

int n;
vector<int> d;
void input() {
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	return;
}
lint solve() {
	if (n == 1) return 1;
	map<int, int> p;
	for (int i = 0; i < n; i++) {
		p[d[i]]++;
	}
	if (n % 2 == 0) {
		bool h = true;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				if (p[i] != 0) { h = false; break; }
			}
			else{
				if (p[i] != 2) { h = false; break; }
			}
		}
		if (h) {
			lint ans = 2;
			for (int i = 0; i < n - 2; i += 2) {
				ans *= 2;
				ans %= mod;
			}
			return ans;
		}
		else 
			return 0;
	}
	if (n % 2 == 1) {
		bool h = true;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (p[i] != 1) { h = false; break; }
				else continue;
			}
			if (i % 2 == 1) {
				if (p[i] != 0) { h = false; break; }
			}
			else {
				if (p[i] != 2) { h = false; break; }
			}
		}
		if (h) {
			lint ans = 2;
			for (int i = 0; i < n - 4; i += 2) {
				ans *= 2;
				ans %= mod;
			}
			return ans;
		}
		else 
			return 0;
	}
}

int main(void) {
	input();
	printf("%lld\n", solve());
	
	return 0;
}