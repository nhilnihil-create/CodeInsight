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
vector<int> ch[100005];
int K, ans;
int go(int x) {
	int mx = 0;
	for (int y : ch[x]) {
		int h = go(y) + 1;
		if (h == K && x != 1) ++ans;
		else mx = max(mx, h);
	}
	return mx;
}
int main() {
	int N;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		int p;
		scanf("%d", &p);
		if (i == 1 && p != 1) ++ans;
		if (i != 1) ch[p].push_back(i);
	}
	go(1);
	printf("%d\n", ans);
}
