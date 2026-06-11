#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n, k, a[6000];
bool c[6000], d[6000];
vector<int> u[6000];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);

	c[0] = true;
	u[n].emplace_back(0);
	for (int i = n - 1; 0 <= i; i--) {
		for (int w = k - 1; 0 <= w; w--)
			if (c[w] && w + a[i] < k)
				c[w + a[i]] = true;
		for (int w = 0; w < k; w++)
			if (c[w])
				u[i].emplace_back(w);
	}

	int count = 0;
	d[0] = true;
	for (int i = 0; i < n; i++) {
		bool any = false;
		for (int w = 0; w < k && (!any); w++) {
			if (!d[w])
				continue;
			int p = lower_bound(u[i + 1].begin(), u[i + 1].end(), k - w) - u[i + 1].begin();
			if (p <= 0)
				continue;
			if (k <= u[i + 1][p - 1] + w + a[i])
				any = true;
		}
		if (!any)
			count++;
		for (int w = k - 1; 0 <= w; w--)
			if (d[w] && w + a[i] < k)
				d[w + a[i]] = true;
	}
	printf("%d\n", count);
}