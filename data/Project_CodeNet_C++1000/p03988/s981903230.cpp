#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	int d = 0;
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		++num[a];
		d = max(d, a);
	}
	auto no = []() {
		printf("Impossible\n");
		exit(0);
	};
	for (int i = (d - 1) / 2; i >= 0; --i)
		if (num[i] > 0) no();
	if (num[(d + 1) / 2] != 1 + d % 2) no();
	for (int i = d; i > (d + 1) / 2; --i)
		if (num[i] < 2) no();
	printf("Possible\n");
}