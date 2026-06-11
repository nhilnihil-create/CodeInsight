#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int S = 205;

LL n;
int bit[60], m;
int s[S], tot;

int main() {
	cin >> n;
	for (m = -1; n > 0; n >>= 1)
		bit[++m] = n & 1;
	
	for (int i = 1; i <= m; i++) s[++tot] = i;
	for (int i = 1; i <= m; i++) s[++tot] = i;
	int Max = (s[++tot] = m+1, s[++tot] = m+1);
	
	for (int i = m-1; i >= 0; i--) if (bit[i]) {
		for (int j = ++tot; j >= i+2; j--)
			s[j] = s[j-1];
		s[i+1] = ++Max;
		s[++tot] = Max;
	}
	
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++)
		printf("%d ", s[i]);
	puts("");
	
	return 0;
}