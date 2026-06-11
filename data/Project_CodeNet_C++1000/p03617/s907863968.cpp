#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;


int main(void) {
	ll q, h, s, d, n, s1, s2, s3, ans;

	scanf("%lld%lld%lld%lld%lld", &q, &h, &s, &d, &n);

	s1 = min(q * 2, h);
	s2 = min(s1 * 2, s);
	s3 = min(s2 * 2, d);

	ans = n / 2 * s3 + n % 2 * s2;

	printf("%lld\n", ans);

	return 0;
}