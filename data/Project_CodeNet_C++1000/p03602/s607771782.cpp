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

int G[301][301];
bool checked[301][301];

signed main() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			if(i!=j) G[i][j] = G[j][i] = LL_HALFMAX;
			else G[i][j] = G[j][i] = 0;
		}
	}
	
	int N;
	cin >> N;

	int sum = 0;
	int minus = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int inp;
			cin >> inp;
			G[i][j] = G[j][i] = inp;
			if (i > j)sum += inp;
		}
	}

	//WFをする
	bool flag = true;
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == k || j == k) continue;
				if (G[i][j] > G[i][k] + G[k][j]) {
					flag = false;
					G[i][j] = G[j][i] = G[i][k] + G[k][j];
				}

				if (i > j)continue;
				if (G[i][j] == G[i][k] + G[k][j] && !checked[i][j] && !checked[j][i]) {
					checked[i][j] = checked[j][i] = true;
					minus -= G[i][j];
				}
			}
		}
	}
	if (flag) cout << sum + minus << "\n";
	else cout << "-1\n";


	return 0;
}