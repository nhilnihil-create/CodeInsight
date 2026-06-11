#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto x : v) cerr << x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int i = 0; i < (n); ++i) cerr << a[i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
int main() {
	int x;
	scanf("%d", &x);
	for (int i = 1;; ++i) {
		int v = i * (i + 1) / 2;
		if (v >= x) {
			printf("%d\n", i);
			break;
		}
	}
}
