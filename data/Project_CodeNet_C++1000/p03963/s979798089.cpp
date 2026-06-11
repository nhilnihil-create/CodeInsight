#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);

	// k * k - 1 * k - 1 ...
	int ans = pow((k - 1), (n - 1)) * k;
	
	printf("%d\n", ans);
	return 0;
}