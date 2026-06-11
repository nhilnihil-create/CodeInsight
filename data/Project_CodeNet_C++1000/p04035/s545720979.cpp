#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, l, i, a[100003], mt;

	scanf("%d%d", &n, &l);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++) {
		if (a[i] + a[i + 1] >= l) {
			break;
		}
	}

	if (i == n - 1) {
		printf("Impossible\n");
		return 0;
	}

	printf("Possible\n");

	mt = i;
	for (i = 0; i < mt; i++) {
		printf("%d\n", i + 1);
	}
	for (i = n - 2; i >= mt; i--) {
		printf("%d\n", i + 1);
	}

	return 0;
}