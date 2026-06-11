// type b
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
#define mod = (lint)1000000007;
#pragma endregion

int h, w, a, b;
bool input() {
	cin >> h >> w >> a >> b;
	if (h % a == 0 && w % b == 0) {
		puts("No");
		return false;
	}
	else return true;
}
void solve() {
	puts("Yes");
	if (h % a != 0) {
		vector<lint> H(h + 1);
		H[0] = 0;
		for (int i = 1; i <= h; i++) {
			if (i < a) {
				H[i] = 10000000;
			}
			else {
				H[i] = H[i - a] - 1;
			}
		}
		vector<lint> ans(h);
		for (int i = 0; i < h; i++) {
			ans[i] = H[i + 1] - H[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << ans[i];
				if (j != w - 1) cout << ' ';
				else cout << endl;
			}
		}
		return;
	}
	else {
		vector<lint> W(w + 1);
		W[0] = 0;
		for (int i = 1; i <= w; i++) {
			if (i < b) {
				W[i] = 10000000;
			}
			else {
				W[i] = W[i - b] - 1;
			}
		}
		vector<lint> ans(w);
		for (int i = 0; i < w; i++) {
			ans[i] = W[i + 1] - W[i];
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << ans[j];
				if (j != w - 1) cout << ' ';
				else cout << endl;
			}
		}
		return;
	}
}

int main(void) {
	if (!input()) return 0;
	solve();
	
	return 0;
}