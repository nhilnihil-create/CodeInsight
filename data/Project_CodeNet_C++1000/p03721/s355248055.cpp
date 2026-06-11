//#pragma warning(disable:4996)
//#include <Windows.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

template<class T>
inline void chmin(T& a, T b) {
	a = min(a, b);
}

template<class T>
inline void chmax(T& a, T b) {
	a = max(a, b);
}

void input();
void solve();

void daminput();

int main() {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	input();
	//daminput();
	solve();
	return 0;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

int N;
LL K;
VI A, B;

void input() {
	cin >> N >> K;
	A.resize(N);
	B.resize(N);
	for (int n = 0; n < N; n++)
	{
		cin >> A[n] >> B[n];
	}
}

void daminput() {
}

void solve() {
	vector<PLL> querys;
	for (int n = 0; n < N; n++)
	{
		querys.push_back(PLL(A[n], B[n]));
	}
	sort(querys.begin(), querys.end(), [](PLL a, PLL b) {
		return a.first < b.first;
	});
	for (int n = 1; n < N; n++)
	{
		querys[n].second += querys[n - 1].second;
	}
	int s = -1, e = N;
	while (e - s > 1) {
		int m = (e + s) / 2;
		if (querys[m].second < K)s = m;
		else e = m;
	}
	cout << querys[e].first << "\n";
}