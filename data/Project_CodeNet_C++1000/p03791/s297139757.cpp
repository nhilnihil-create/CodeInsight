#include <cstdio>
#define MOD 1000000007
using namespace std;

int n;
int lower_bound = 1, cnt = 0;

int main() {
	scanf("%d", &n);
	long long ret = 1;

	for (int i = 0; i < n; i++) {
		int pos;
		scanf("%d", &pos);
		ret = (ret * (cnt + 1)) % MOD;
		if (lower_bound <= pos) {
			lower_bound += 2;
			cnt++;
		}
	}
	printf("%lld\n", ret);
	return 0;
}