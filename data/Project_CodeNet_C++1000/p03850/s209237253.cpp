// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <numeric>
#include <functional>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;


int main() {
//	freopen("brackets.in", "r", stdin);
//	freopen("brackets.out", "w", stdout);
	
	int n;
	ll ans, ans2;
	bool f = false;
	ll csum = 0;
	scanf("%d%lld", &n, &ans);
	ans2 = -1LL << 60;
	
	while (--n) {
		char op;
		int x;
		scanf(" %c%d", &op, &x);
		if (op == '+') {
			if (!f) {
				ans += x;
			} else {
				csum += x;
				ans2 += x;
			}
		} else if (op == '-') {
			if (!f) {
				f = true;
				ans -= x;
			} else {
				ans2 = max(ans2 + x, ans - csum + x);
				ans += csum - x;
				csum = 0;
			}
		}
	}
	printf("%lld\n", max(ans + csum, ans2));
	
	return 0;
}