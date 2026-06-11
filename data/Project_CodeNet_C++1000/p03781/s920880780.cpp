#include <bits/stdc++.h>
using namespace std;

int main() {
	int x; scanf("%d", &x);
	int st = 0, ed = x;
	while(ed - st > 1) {
		int mid = st + ed >> 1;
		if((long long)mid * (mid + 1) < x * 2) st = mid;
		else ed = mid;
	}
	printf("%d\n", st + 1);
	return 0;
}
