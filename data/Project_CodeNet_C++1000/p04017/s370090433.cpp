//#pragma warning(disable:4996)
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
const long long INF = 1e15;
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin >> N;
	VLL X(N);
	for (int n = 0; n < N; n++)cin >> X[n];
	LL L;
	int Q;
	cin >> L >> Q;
	VVI front;
	front.resize(N, VI(20));
	for (int n = 0; n < N; n++) {
		//[x_n,x_s] <= L < [x_n,x_e]
		int s = n, e = N;
		while (e - s > 1) {
			int m = (e + s) / 2;
			if (X[m] - X[n] <= L)s = m;
			else e = m;
		}
		front[n][0] = s;
	}
	for (int c = 1; c < 20; c++) {
		for (int n = 0; n < N; n++) {
			int prev = front[n][c - 1];
			if (prev == N)front[n][c] = N;
			else front[n][c] = front[prev][c - 1];
		}
	}
	VVI back;
	back.resize(N, VI(20));
	for (int n = 0; n < N; n++) {
		//[x_s,x_n] < L <= [x_e,x_n]
		int s = -1, e = n;
		while (e - s > 1) {
			int m = (e + s) / 2;
			if (X[n] - X[m] > L)s = m;
			else e = m;
		}
		back[n][0] = e;
	}
	for (int c = 1; c < 20; c++) {
		for (int n = 0; n < N; n++) {
			int prev = back[n][c - 1];
			if (prev == -1)back[n][c] = -1;
			else back[n][c] = back[prev][c - 1];
		}
	}
	for (int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a < b) {
			//s日到達 < b <= e日到達
			int s = 0, e = (1 << 20);
			while (e - s > 1) {
				int m = (e + s) / 2;
				int n = a;
				for (int c = 0; c < 20; c++) {
					if ((m & (1 << c)) != 0) {
						n = front[n][c];
					}
				}
				if (n < b)s = m;
				else e = m;
			}
			cout << e << "\n";
		}
		else {
			//s日到達 > b >= e日到達
			int s = 0, e = (1 << 20);
			while (e - s > 1) {
				int m = (e + s) / 2;
				int n = a;
				for (int c = 0; c < 20; c++) {
					if ((m & (1 << c)) != 0) {
						n = back[n][c];
					}
				}
				if (n > b)s = m;
				else e = m;
			}
			cout << e << "\n";
		}
	}
	return 0;
}