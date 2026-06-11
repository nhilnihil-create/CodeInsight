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
	int n, L;
	scanf("%d%d", &n, &L);
	vector<int> A(n);
	int p = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
		if (i && A[i] + A[i - 1] >= L) {
			p = i - 1;
		}
	}
	if (p == -1) printf("Impossible\n");
	else {
		vector<int> ans;
		for (int j = p; j + 1 < n; ++j) ans.push_back(j + 1);
		for (int j = p - 1; j >= 0; --j) ans.push_back(j + 1);
		reverse(ans.begin(), ans.end());
		printf("Possible\n");
		for (int x : ans) printf("%d\n", x);
	}
}
