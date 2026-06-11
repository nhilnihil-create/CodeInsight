#include "bits/stdc++.h"
using namespace std;
const int MAX = 700000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
vector<vector<pair<int, int>>> s(100030);
long long int seen[100020] = {};
long long int value[100020] = {};
int main() {
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<int>s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	int number = 0;
	int od = 0;
	int ans[120][120] = {};
	for (int i = 0; i < h; i++) {
		if (od == 0) {
			for (int j = 0; j < w; j++) {
				if (s[number] == 0) {
					number = number + 1;
				}
				s[number] = s[number] - 1;
				ans[i][j] = number + 1;
			}
			od = 1;
		}
		else {
			for (int j = w-1; j >= 0; j--) {
				if (s[number] == 0) {
					number = number + 1;
				}
				s[number] = s[number] - 1;
				ans[i][j] = number + 1;
			}
			od = 0;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}