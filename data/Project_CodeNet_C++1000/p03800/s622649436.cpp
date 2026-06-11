#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 998244353
#define inf 10000000000000007
#define all(vec) vec.begin(),vec.end()
#define ggr getchar(); getchar();return 0;
#define ll long long
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

int kai(int x) {
	if (x == 1)return 1;
	return kai(x - 1)*x;
}

int mod_pow(int x, int y, int moder) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%moder;
		x = x * x%moder;
		y >>= 1;
	}
	return res;
}

int n;
string s;
char ta[4][100010];

signed main() {
	cin >> n >> s;
	ta[0][0] = 'S';
	ta[0][1] = 'S';
	ta[1][0] = 'S';
	ta[1][1] = 'W';
	ta[2][0] = 'W';
	ta[2][1] = 'S';
	ta[3][0] = 'W';
	ta[3][1] = 'W';
	for (int i = 2; i < n; i++) {
		rep(j, 4) {
			if (s[i - 1] == 'o') {
				if (ta[j][i - 1] == 'S')ta[j][i] = ta[j][i - 2];
				else if (ta[j][i - 2] == 'S')ta[j][i] = 'W';
				else ta[j][i] = 'S';
			}
			else {
				if (ta[j][i - 1] == 'W')ta[j][i] = ta[j][i - 2];
				else if (ta[j][i - 2] == 'S')ta[j][i] = 'W';
				else ta[j][i] = 'S';
			}
		}
	}
	bool mu = true;
	rep(i, 4) {
		if (ta[i][n - 1] == 'S') {
			if (s[n - 1] == 'o'&&ta[i][n - 2] != ta[i][0])mu = false;
			else if (s[n - 1] == 'x'&&ta[i][n - 2] == ta[i][0])mu = false;
		}
		else {
			if (s[n - 1] == 'o'&&ta[i][n - 2] == ta[i][0])mu = false;
			else if (s[n - 1] == 'x'&&ta[i][n - 2] != ta[i][0])mu = false;
		}
		if (ta[i][0] == 'S') {
			if (s[0] == 'o'&&ta[i][n - 1] != ta[i][1])mu = false;
			else if (s[0] == 'x'&&ta[i][n - 1] == ta[i][1])mu = false;
		}
		else {
			if (s[0] == 'o'&&ta[i][n - 1] == ta[i][1])mu = false;
			else if (s[0] == 'x'&&ta[i][n - 1] != ta[i][1])mu = false;
		}
		if (mu) {
			rep(j, n) {
				cout << ta[i][j];
			}
			cout << endl;
			return 0;
		}
		mu = true;
	}
	cout << -1 << endl;
	return 0;
}