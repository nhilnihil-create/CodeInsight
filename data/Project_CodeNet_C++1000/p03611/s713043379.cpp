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
	int n;
	S(n);
	int a[100000] = { 0 };
	R(i, n) {
		int num;
		S(num);
		if(num != 0) a[num - 1]++;
		a[num]++;
		if(num != 99999) a[num + 1]++;
	}
	int ans = 0;
	R(i, 100000) ans = max(ans, a[i]);
	P(ans);
}