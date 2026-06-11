#include <bits/stdc++.h>

using namespace std;

int n;
int arr[110000];

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	
	long long mod = 1000000007;
	long long ans = 1;
	long long pos = 0;
	int ptr = 0;
	int holds = 0;
	
	for (int i = 0; i < n; ++i) {
		while (ptr < n) {
			long long npos = arr[ptr];
			if ((npos - 1) < holds * 2) {
				break;
			}
			pos = npos;
			++holds;
			++ptr;
		}
		if (ptr < n && arr[ptr] == arr[ptr - 1] + 1) {
			++pos;
			++ptr;
			++holds;
		}
		ans = (ans * holds) % mod;
		//printf("%d %d\n", i + 1, holds);
		--holds;
	}
	
	printf("%lld\n", ans);
	
    return 0;
}
