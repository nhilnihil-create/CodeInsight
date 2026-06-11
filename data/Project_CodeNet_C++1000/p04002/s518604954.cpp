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
#define int long long
#define double long double
#define oku7 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
using namespace std;
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

map<pair<int, int>, int> ma;
int ans[10];
signed main() {
	int H, W, N;
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int y = a + dy;
				int x = b + dx;
				if (y <= 1 || x <= 1 || y >= H || x >= W) continue;
				pair<int, int> p = make_pair(x, y);
				ma[p]++;
			}
		}
	}
	int sum = 0;
	for (pair<pair<int,int>,int> p : ma) {
		ans[p.second]++;
		sum++;
	}
	ans[0] = (H - 2)*(W - 2) - sum;

	for (int i = 0; i < 10; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}