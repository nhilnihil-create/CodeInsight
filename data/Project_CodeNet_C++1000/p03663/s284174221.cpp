#include <iostream>
#include <cstdio>

using namespace std;

char s[2];
void query(long long x) { printf("? %lld\n",x); fflush(stdout); scanf("%s",s); }

void work(int MAX) {
	long long l = MAX, r = MAX * 10 - 1, mid, res = r;
	while(l <= r) {
		mid = l + r >> 1;
		query(mid * 10);
		if(s[0] == 'Y') {
			if(mid < res) res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("! %lld\n", res);
}

int main() {
	query(1e9);
	if(s[0] == 'Y') {
		int cur = 1e9;
		for(int i = 9; i; --i, cur /= 10) {
			query(cur - 1);
			if(s[0] == 'N') break;
		}
		printf("! %d\n", cur);
		return 0;
	}
	for(int cur = 1000000000, bit = 10; true; cur /= 10, --bit) {
		query(cur);
		if(s[0] == 'Y') {
			work(cur);
			break;
		}
	}
	return 0;
}