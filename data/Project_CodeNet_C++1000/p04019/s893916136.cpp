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
char str[1005];
int main() {
	scanf("%s", str);
	int n = strlen(str);
	int up = 0, down = 0, left = 0, right = 0;
	for (int i = 0; i < n; ++i) {
		up |= str[i] == 'N';
		down |= str[i] == 'S';
		left |= str[i] == 'W';
		right |= str[i] == 'E';
	}
	if (up != down || left != right) printf("No\n");
	else printf("Yes\n");
}
