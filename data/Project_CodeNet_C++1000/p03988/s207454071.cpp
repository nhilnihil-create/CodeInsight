#include <bits/stdc++.h>
using namespace std;

int n, f[105];

int main() {
	scanf("%d", &n);

	int mn = 1e9;
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		f[x]++;
		mn = min(mn, x);
	}

	if(f[mn] > 2) {
		printf("Impossible\n");
		return 0;
	}

	int up = 2 * mn - (f[mn] == 2);

	for(int i = mn + 1; i <= up; i++) {
		if(f[i] < 2) {
			printf("Impossible\n");
			return 0;
		}
	}

	for(int i = up + 1; i <= 100; i++) {
		if(f[i] > 0) {
			printf("Impossible\n");
			return 0;
		}
	}

	/*for(int i = mn + 2; i <= up; i++) {
		if(f[i] > f[i - 1]) {
			printf("Impossible\n");
			return 0;
		}
	}*/

	printf("Possible\n");
	return 0;
}