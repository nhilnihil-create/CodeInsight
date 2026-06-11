#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define bs(n) (1ull<<(n))

ull cmb(int n, int k) {
	return k == 0 ? 1 : (cmb(n - 1, k - 1) * n) / k;
}

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	ull* v = new ull[n];
	rep(i, n)cin >> v[i];
	sort(v, v + n, greater<>());
	ull m = v[a - 1], s = 0,c = 0, d = 0, r = 0;
	for (int i = 0; i < n; i++)if (v[i] == m)c++;
	for (int i = 0; i < a; i++)if (v[i] == m)d++;
	for (int i = 0; i < a; i++) s += v[i];
	if (s == m * a) {
		for (int i = a; i <= b; i++) {
			r += cmb(c, i);
		}
	}
	else {
		r += cmb(c, d);
	}
	cout << setprecision(20) << ((double)s) / a << endl << r << endl;
}
