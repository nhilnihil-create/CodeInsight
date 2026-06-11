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
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位



int x[100001], y[100001];
int a[200001];
int bo[100][100];
map<int, vector<int>> ma;

int grundyNumber(int l,int r) {
	if ((l == 0 && r == 0) ||
		(l == 1 && r == 0) ||
		(l == 0 && r == 1) ||
		(l == 1 && r == 1))
	{
		bo[l][r] = 0;
		return 0;
	}
	if (bo[l][r] != -1) return bo[l][r];
	set<int> s;
	for (int i = 1; i <= l / 2; i++) {
		s.insert(grundyNumber(l - 2 * i, r + i));
	}
	for (int i = 1; i <= r / 2; i++) {
		s.insert(grundyNumber(l + i, r - 2 * i));
	}
	int res = 0;
	while (s.find(res) != s.end()) res++;
	bo[l][r] = bo[r][l] = res;
	return res;
}

signed main() {
	int X, Y;
	cin >> X >> Y;
	//if (X > 100 || Y > 100) return 1;
	/*
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			bo[i][j] = -1;
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			grundyNumber(i, j);
		}
	}*/
	if (abs(X - Y) <= 1) cout << "Brown\n";
	else cout << "Alice\n";
	

	return 0;
}