#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> x(n);
	rep(i, n) scanf("%d", &x[i]);
	int ans = 0;
	rep(i, n) {
		if(k - x[i] <= x[i]) ans += (k - x[i]) * 2;
		else ans += x[i] * 2;
	}
	printf("%d\n", ans);
	return 0;
}