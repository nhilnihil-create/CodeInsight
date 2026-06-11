#include <bits/stdc++.h>

int n, a[100010], cnt[2], rem, first = 0, second = 1;
char ans[2][7] = {\
	{'F', 'i', 'r', 's', 't', 0, 0},\
	{'S', 'e', 'c', 'o', 'n', 'd', 0}\
};

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		cnt[a[i] & 1]++;
		if(a[i] & 1) {
			rem = i;
		}
	}
	for(;;) {
		if(cnt[0] & 1) {
			return !puts(ans[first]);
		}
		if(cnt[1] != 1 || a[rem] == 1) {
			return !puts(ans[second]);
		}
		first ^= 1;
		second ^= 1;
		--a[rem];
		int d = a[1];
		for (int i = 2; i <= n; ++i) {
			d = std::__gcd(d, a[i]);
		}
		cnt[0] = cnt[1] = 0;
		for (int i = 1; i <= n; ++i) {
			a[i] /= d;
			cnt[a[i] & 1]++;
			if(a[i] & 1) {
				rem = i;
			}
		}
	}
	return 0;
}