#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
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

// ===============================================================

using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;

// ===============================================================

ll gcd(ll a, ll b) //最大公約数
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

ll lcm(ll a, ll b) //最小公倍数
{
	return a * b / gcd(a, b);
}

ll box(double a) //doubleの切り捨て
{
	ll b = a;
	return b;
}

ll fff(double a) //doubleの四捨五入
{
	ll b = a + 0.5;
	return b;
}

ll sum(ll n) { //整数sまでの合計
	if (n == 0) {
		return 0;
	}

	int s = sum(n - 1);
	return s + n;
}

bool prime(ll num)//素数判定、primeならtrue,違うならfalse
{
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false;
	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	// 素数である
	return true;
}

// ===============================================================

int main() {
	ll a;
	cin >> a;
	vl data(a+10, 1);
	for (int i = 2; i <= a; i++) {
		ll e = i;
		for (int j = 2; j * j <= i; j++) {
			ll count = 0;
			while (e % j == 0) {
				e /= j;
				count++;
			}
			data[j] += count;
		}
		if (e != 1) {
			data[e]++;
		}
	}
	ll ans = 1;
	for (int i = 1; i < a+5; i++) {
		ans *= data[i];
		ans %= 1000000007;
	}
	cout << ans << endl;
}