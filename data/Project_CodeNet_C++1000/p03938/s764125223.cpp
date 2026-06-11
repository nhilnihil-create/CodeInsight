#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(x, a, b) for(int x = (a); x <= (b); ++x)
#define rop(x, a, b) for(int x = (a); x < (b); ++x)
#define per(x, a, b) for(int x = (a); x >= (b); --x)
using namespace std;
typedef long long LL;
typedef double DB;
int n, a[100005], wz[100005];
int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), wz[a[i]] = i;
	rep(i, 1, n) printf("%d ", i * n);
	puts("");
	rep(i, 1, n) printf("%d ", (n - i + 1) * n + wz[i] - 1);
	return 0;
}
