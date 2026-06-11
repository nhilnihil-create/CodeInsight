#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#define _USE_MATH_DEFINES
#include<math.h>
#include<cmath>
#include<ctime>
#include<map>
#include<typeinfo>
#define R(i, n) for(int i = 0;i < n; i++)
#define R1(i, n) for(int i = 1; i <= n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define SL2(a, b) scanf("%lld%lld", &a, &b)
#define SL3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SC(a) scanf("%c", &a)
#define P(a) printf("%d", a)
#define PL(a) printf("%lld", a)
#define PY printf("YES")
#define PN printf("NO")
#define Py printf("Yes")
#define Pn printf("No")
using namespace std;
using ll = long long;
using PR = pair<int, int>;
const ll MOD = 1e+9 + 7;
const int INF = 1e+9;
const double PI = acos(-1);

int main() {
	ll q, h, s, d, n;
	SL3(q, h, s);
	SL2(d, n);
	h = min(q * 2, h);
	s = min(h * 2, s);
	ll ans;
	if (d < s * 2) {
		ans = n / 2 * d + n % 2 * s;
	}
	else {
		ans = n * s;
	}
	PL(ans);
}