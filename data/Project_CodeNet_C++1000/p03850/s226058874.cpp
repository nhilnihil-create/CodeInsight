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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
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
	double kaku = acos(cosine);
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
		int starter = ans[ans.size() - 1];
		for (int i = 0; i < a.size(); ++i) {
			if (i != starter) {
				double goa = angles(ba, a[i] - a[starter]);
				if (goa > now_min) {
					now_min = goa;
					now_go = i;
				}
			}
		}
		if (now_go == ans[0]) break;
		ans.push_back(now_go);
		ba = complex<double>(a[now_go] - a[starter]);
	}
	return ans;
}
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long dp[200000][3] = {};
int main(){
#define int long long
	int n;
	cin >> n;
	vector<int> inputs;
	int a;
	cin >> a;
	inputs.push_back(a);
	REP(i, n - 1) {
		int a;
		string b;
		cin >> b >> a;
		if (b == "+") {
			inputs.push_back(a);
		}
		else {
			inputs.push_back(-a);
		}
	}
	REP(i, 200000) {
		REP(q, 3) {
			dp[i][q] = -LONG_INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < inputs.size(); ++i) {
		for (int q = 0; q < 3; ++q) {
			if (inputs[i] < 0) {
				if (q == 0) {
					dp[i + 1][1] = max(dp[i + 1][1], dp[i][q] + inputs[i]);
				}
				else {
					dp[i + 1][1] = max(dp[i + 1][1], dp[i][q] + inputs[i]);
					dp[i + 1][2] = max(dp[i + 1][2], dp[i][q] - inputs[i]);
				}
			}
			else {
				for (int j = 0; j <= q; ++j) {
					int geko = 1;
					REP(t, j) {
						geko *= -1;
					}
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][q] + geko * inputs[i]);
				}
			}
		}
	}
	long long ans = max({ dp[n][0],dp[n][1],dp[n][2] });
	cout << ans << endl;
}