#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int divMax = 0;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int tmp = i;
		while (tmp > 0) {
			// cout << tmp << "\n";
			if (tmp % 2 == 0) {
				tmp /= 2;
				cnt++;
			} else {
				break;
			}
		}
		if (cnt > divMax) {
			divMax = cnt;
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
