#include <bits/stdc++.h>
using namespace std;

const int MAXN = 123;
int N;
int freq[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int d; scanf("%d", &d);
		freq[d]++;
	}
	bool ans = true;
	int diam = N-1;
	while (freq[diam] == 0) diam--;
	int mi = 0;
	while (freq[mi] == 0) mi++;
	ans &= (mi == (diam + 1) / 2);
	ans &= (freq[mi] == (diam % 2) + 1);
	for (int i = mi+1; i <= diam; i++) ans &= (freq[i] >= 2);
	if (ans) puts("Possible");
 	else puts("Impossible");

	return 0;
}
