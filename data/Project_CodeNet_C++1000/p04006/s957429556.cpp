#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)
typedef long long LL;
const int maxn = 2005;
LL a[maxn], m[maxn];
int main() {
	LL n, cnt, sum = 0;
	scanf("%lld%lld", &n, &cnt);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		m[i] = a[i];
		sum += a[i];
	}
	LL Min = sum; int p;
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			p = i - k < 0 ? i - k + n : i - k;
			if (a[p] < m[i]) {
				sum -= m[i] - a[p];
				m[i] = a[p];
			}
		}
		Min = min(Min, sum + cnt * k);
	}
	printf("%lld\n", Min);
}