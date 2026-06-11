#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

#define roop(i, n) for(int i=0;i<n;i++)

using namespace std;
using ll = long long int;
using ull = unsigned long long;

constexpr ull mod = 1e9+7;
constexpr int N = 13;
ull dp[100010][N];

float myPower(int a, int n) { // aのn乗の計算
	float x = 1;
	while (n > 0) { // 全てのbitが捨てられるまで
		if ( n & 1) { // 一番右のbitが１のとき
			x *= a;
		}
		a *= a;
		n >>= 1; // bit全体を右に1つシフトして一番右を捨てる
	}
	return x;
}

int main() {
	int n;
	cin >> n;
	ll T = 1, A = 1;
	for (int i = 0; i < n; i++) {
		int t, a;
		cin >> t >> a;
		ll s = max( (T + t - 1)/t, (A + a - 1)/a);
		T = s * t;
		A = s * a;
	}
	cout << T + A << endl;
	return 0;
}