#include <bits/stdc++.h>
using namespace std;

#define LL long long

char st[10];

bool fuck(LL x) {
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", st);
	return st[0] == 'Y';
}

int main() {
	int l = 0, r;
	bool flag = 1;
	for (int i=1; i<=1e9; i*=10) {
		if (!fuck(i)) {
			flag = 0;
			if (l == 0) l = i / 10;
		}
	}

	if (flag) {
		for (int i=1; i<=1e9; i*=10) {
			if (fuck(i*10LL-1)) {
				printf("! %d\n", i);
				fflush(stdout);
				return 0;
			}
		}
	}

	r = l * 10 - 1;
	l = l + 1;
	// printf("%d %d", l, r);
	while (l < r) {
		int mid = (l + r) / 2;
		if (fuck(mid * 10LL + 1)) r = mid;
		else l = mid + 1;
	}

	printf("! %d\n", r);
	fflush(stdout);

	return 0;
}