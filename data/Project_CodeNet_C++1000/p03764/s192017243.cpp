#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#define int long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

using namespace std;
using namespace std;

std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

int x[100001], y[100000];

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	int mx = 0, left = 1, right = n - 1;
	for (int i = 0; i < n-1; i++) {
		int addNum = abs(x[i] - x[i+1]);
		addNum = (addNum % mod) * (left % mod);
		addNum = (addNum % mod) * (right % mod);
		left++;
		right--;
		mx += addNum;
		mx %= mod;
	}
	int my = 0, down = 1, up = m - 1;
	for (int i = 0; i < m - 1; i++) {
		int addNum = abs(y[i] - y[i + 1]);
		addNum = (addNum % mod) * (down % mod);
		addNum = (addNum % mod) * (up % mod);
		down++;
		up--;
		my += addNum;
		my %= mod;
	}

	
	cout << ((mx % mod) * (my % mod) % mod) << "\n";

	return 0;
}