#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	
	int ans = 0;
	sort(a + 1, a + 1 + n); reverse(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++ i) {
		if (i >= a[i + 1]) {
			for (int j = i + 1; a[j] == i; ++ j) ans ^= 1;
			ans |= (a[i] - i) & 1;
			puts(ans ? "First" : "Second");
			return 0;
		}
	}
	return 0;
}