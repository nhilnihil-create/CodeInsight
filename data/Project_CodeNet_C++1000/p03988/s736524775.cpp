#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>

#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <tuple>

using namespace std;

using ii = pair < int, int >;
using ti = tuple < int, int, int>;
using lint = long long;

const int N = 105;

int a[N];

vector < int > v;
bool c[N];

int n;
int mx;

bool rem() {
	sort(v.begin(), v.end());
	auto t = v.end();
	t--;
	mx = *t;
	for (int i = 0; i <= mx; i++) {
		int val;
		val = max(mx - i, i);
		bool o = false;
		for (int i = 0; i < n; i++) {
			if (!c[i] && v[i] == val) {
				c[i] = true;
				o = true;
				break;
			}
		}
		if (!o)return false;
	}
	return true;
}

bool chk() {
	if (n == mx-1)return true;
	int lb = mx / 2 + mx % 2 + 1;
	int ub = mx;
	for (size_t i = 0; i < n; i++) {
		if (c[i])continue;
		if (v[i] < lb || ub < v[i]) {
			return false;
		}
	}
	return true;
}

#define Ia

int main() {
#ifdef I
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		v.push_back(a[i]);
	}
	if (rem()) {
		if (chk()) {
			puts("Possible");
		}
		else {
			puts("Impossible");
		}
	}
	else {
		puts("Impossible");
	}
	return 0;
}
