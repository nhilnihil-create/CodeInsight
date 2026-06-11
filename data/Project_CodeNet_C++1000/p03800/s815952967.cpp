#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int INF = 2e9;



int main() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> ans(n);
	rep(a, 0, 2)rep(b, 0, 2) {
		ans[0] = a; ans[1] = b;
		rep(i, 2, n) {
			int flag = (s[i - 1] != 'o');
			if (ans[i - 1] == 1) flag ^= 1;
			ans[i] = ans[i - 2] ^ flag;
		}
		bool fl = true;
		rep(i, 0, n) {
			int x = i, y = (i + 1) % n, z = (i + 2) % n;
			int flag = (s[y] != 'o');
			if (ans[y] == 1) flag ^= 1;
			if ((ans[x] ^ flag)!=ans[z]) fl = false;
		}
		if (fl) {
			rep(i, 0, n) printf("%c", (ans[i] == 0 ? 'S' : 'W'));
			return 0;
		}
	}
	printf("-1");
	return 0;
}
