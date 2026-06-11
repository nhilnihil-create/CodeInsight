#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 10000000000000007
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

long long a, b, c, d, e, f, g;

signed main() {
	cin >> a >> b >> c >> d >> e >> f >> g;
	if ((a % 2 == 1 && d % 2 == 1 && e % 2 == 1) || (a % 2 == 0 && d % 2 == 0 && e % 2 == 0))cout << a + b + d + e << endl;
	else if (a < 2 && d < 2 && e < 2)cout << b << endl;
	else cout << a + b + d + e - 1 << endl;
	ggr
}