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
	vector<int> A(n), B(n), P(n);
	const int M = 20005;
	for (int i = 0; i < n; ++i) {
		A[i] = i * M + 1;
		B[i] = (n - 1 - i) * M + 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &P[i]);
		--P[i];
		A[P[i]] += i;
	}
	for (int x : A) printf("%d ", x);
	printf("\n");
	for (int x : B) printf("%d ", x);
	printf("\n");
}
