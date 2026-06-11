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
#define INF (lint)10000000000000000;
#define mod (int)1000000007
#pragma endregion



int main() {
	string a, b, c; cin >> a >> b >> c;
	int x, y, z;
	x = 0; y = 0; z = 0;
	int cnt = 0;
	while (true) {
		if (cnt == 0) {
			if (x == (int)a.size()) {
				puts("A");
				break;
			}
			cnt = (int)a[x] - 97;
			x++;
			continue;
		}
		if (cnt == 1) {
			if (y == (int)b.size()) {
				puts("B");
				break;
			}
			cnt = (int)b[y] - 97;
			y++;
			continue;
		}
		if (cnt == 2) {
			if (z == (int)c.size()) {
				puts("C");
				break;
			}
			cnt = (int)c[z] - 97;
			z++;
			continue;
		}
	}

	return 0;
}