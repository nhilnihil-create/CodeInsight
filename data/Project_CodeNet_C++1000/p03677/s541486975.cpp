#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, w[101000];
long long S1[101000], S2[101000];
void Do(int b, int e) {
	if (b == e)return;
	if (b < e) {
		S1[1] += e - b;
		S1[b + 1] += b + 1;
		S2[b + 1]--;
		S2[e + 1]++;
		S1[e + 1] -= b + 1;
	}
	else {
		S1[1] += e - b + m;
		S2[b + 1]--;

		S1[b + 1] += b + 1;

		S2[1]--;
		S2[e + 1]++;
		S1[1] += b + 1 - m;
		S1[e + 1] -= b + 1 - m;
	}
}
int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (i = 1; i < n; i++)Do(w[i], w[i + 1]);
	long long s1 = 0, s2 = 0;
	long long res = 1e18;
	for (i = 1; i <= m; i++) {
		s1 += S1[i];
		s2 += S2[i];
		res = min(res, s2*i + s1);
	}
	printf("%lld\n", res);
}