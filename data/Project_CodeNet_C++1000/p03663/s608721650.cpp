#include<bits/stdc++.h>
#define int long long
using namespace std;
bool judge(char c, int n) {
	printf("%c %lld\n", c, n);
	fflush(stdout);
	char s[10];
	if (c == '?') {
		scanf("%s", s);
		if (s[0] == 'Y') return 1;
		return 0;
	}
	return 0;
}
signed main() {
	int len = 1, num = 1, flag = 0;
	while (judge('?', num)) {
		len *= 10; num = len;
		if (len > 1E10) {
			flag = 1; break;
		}
	}
	if (flag) {
		len = 10, num = 10, flag = 0;
		while (!judge('?', num - 1)) {
			len *= 10; num = len;
			if (len > 1E9) break;
		}
		judge('!', num / 10);
		return 0;
	}
	len /= 10; num = len;
	while (len) {
		int l = 0, r = 9 - (num / len) % 10;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (!judge('?', (mid * len + num) * 10)) l = mid;
			else r = mid - 1;
		}
		num += l * len;
		len /= 10;
	}
	judge('!',  num + 1);
	return 0;
}