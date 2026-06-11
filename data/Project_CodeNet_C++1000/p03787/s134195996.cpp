/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
double dot(complex<double> a, complex<double> b) {
	return a.real() * b.real() + a.imag() * b.imag();
}
double gyaku_dot(complex<double> a, complex<double> b) {
	return a.real() * b.imag() - a.imag() * b.real();
}
double leng(complex<double> a) {
	return sqrt(a.real() * a.real() + a.imag() * a.imag());
}
double angles(complex<double> a, complex<double> b) {
	double cosine = dot(a, b) / (leng(a) * leng(b));
	double sine = gyaku_dot(a, b) / (leng(a) * leng(b));
	double kaku = acos(min((double)1.0, max((double)-1.0, cosine)));
	if (sine <= 0) {
		kaku = 2 * Ma_PI - kaku;
	}
	return kaku;
}
vector<int> convex_hull(vector<complex<double>> a) {
	vector<int> ans;
	double now_minnest = a[0].real();
	int now_itr = 0;
	REP(i, a.size()) {
		if (now_minnest > a[i].real()) {
			now_minnest = a[i].real();
			now_itr = i;
		}
	}
	ans.push_back(now_itr);
	complex<double> ba(0, 1);
	while (true) {
		int now_go = 0;
		double now_min = 0;
		double now_length = 0;
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa - now_min >= eps || (abs(goa - now_min) <= eps && (abs(a[i] - a[starter]) - now_length) >= eps)) {
					now_min = goa;
					now_go = i;
					now_length = abs(a[i] - a[starter]);
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
vector<int> vertexs[200000];
int visited[200000];
int coloring[200000];
int main() {
#define int long long
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	long long ans = n * n;
	long long cnt[3] = {};
	REP(i, n) {
		coloring[i + 1] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		if (visited[i] == 1) continue;
		visited[i] = 1;
		if (vertexs[i].size() == 0) {
			cnt[0]++;
			continue;
		}
		queue<int> next;
		visited[i] = 1;
		coloring[i] = 0;
		next.push(i);
		int conflict = 0;
		int pre_cnt = 1;
		while (next.empty() == false) {
			int now = next.front();
			next.pop();
			for (int q = 0; q < vertexs[now].size(); ++q) {
				int go = vertexs[now][q];
				if (visited[go] == 1) {
					if (coloring[now] + coloring[go] != 1) {
						conflict = 1;
					}
				}
				else {
					visited[go] = 1;
					coloring[go] = (coloring[now] + 1) % 2;
					next.push(go);
					pre_cnt++;
				}
			}
		}
		if (conflict == 0) {
			cnt[2]++;
		}
		else {
			cnt[1]++;
		}
	}
	ans -= (n - cnt[0]) * (n - cnt[0]);
	ans += (cnt[1] + cnt[2]) * (cnt[1] + cnt[2]);
	ans += cnt[2] * cnt[2];
	cout << ans << endl;
	return 0;
}