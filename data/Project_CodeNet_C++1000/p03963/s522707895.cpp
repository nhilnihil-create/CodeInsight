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
#define R(i, n) for(int i = 0;i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define SL2(a, b) scanf("%lld%lld", &a, &b)
#define SL3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define SA(i, n, a) R(i, n) scanf("%d", a + i)
#define SAL(i, n, a) R(i, n) scanf("%lld", a + i)
#define SC(a) scanf("%c", &a);
#define P(a) printf("%d", a)
#define PL(a) printf("%lld", a)
#define PY printf("Yes");
#define PN printf("No");
#define Py printf("yes");
#define Pn printf("no");
using namespace std;
using ll = long long;
using PR = pair<int, int>;
const ll MOD = 1e+9 + 7;
const int INF = 1e+9;
const double PI = acos(-1);

int N, K;

int main() {
	S2(N, K);
	ll ans = (ll)K * pow(K - 1, N - 1);
	PL(ans);
}