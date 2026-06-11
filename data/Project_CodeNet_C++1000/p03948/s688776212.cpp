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

map<int, int> ma;
vector<pair<int,int>> v;
vector<int> A;
signed main() {
	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}
	int minValue = 1145141919;
	int minInd = -1;
	int value = -1;
	for (int i = 0; i < N; i++) {
		if (minValue > A[i]) {
			minValue = A[i];
			minInd = i;
		}
		if (value <  A[i] - minValue ) {
			value = A[i] - minValue;
			v.clear();
			v.push_back(make_pair(minInd, i));
		}
		else if (value ==  A[i] - minValue) {
			v.push_back(make_pair(minInd, i));
		}

	}
	//区間の端っこを全部入れる
	for (pair<int, int> p : v) {
		ma[p.first]++;
		ma[p.second]++;
	}
	int ans = 0;
	for (pair<int, int> p : v) {
		//すべての区間について端っこが死んでいないか検査、両方とも死んでいなければ多いほうを潰してans++
		if (ma[p.first] == -1 || ma[p.second] == -1) {
			continue;
		}
		if (ma[p.first] > ma[p.second]) {
			ma[p.first] = -1;
			ans++;
		}
		else {
			ma[p.second] = -1;
			ans++;
		}
	}
	cout <<ans << "\n";

	return 0;
}