#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vector<int> vec_w;
	vector<int> vec_s;

	for (int i=0; i<=3000; i++) {
		for (int j=0; j<=3000; j++) {
			if (100*i*a + 100*j*b <= f) vec_w.push_back(100*i*a + 100*j*b);
		}
	}
	for (int i=0; i<=3000; i++) {
		for (int j=0; j<=3000; j++) {
			if (i*c+j*d<=f) vec_s.push_back(i*c+j*d);
		}
	}
	double max_d = 0.0;
	int res_ws = 0;
	int res_s = 0;
	for (auto w: vec_w) {
		for (auto s: vec_s) {
			if (w+s > f) continue;
			double d = 100*s/double(w+s);
			if (d<=e*100/double(100+e) && d>=max_d) {
				max_d = d;
				res_ws = w+s;
				res_s = s;
			}
		}
	}
	cout << res_ws << " " << res_s << endl;
}