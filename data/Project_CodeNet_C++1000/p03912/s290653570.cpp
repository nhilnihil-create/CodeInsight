#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, C[101000], res, P[101000], U[101000];
int main() {
	int i, j, a;
	scanf("%d%d", &n,&m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		C[a]++;
		P[a%m]++;
	}
	for (i = 1; i <= 100000; i++) {
		U[i%m] += C[i] / 2;
	}
	for (i = 0; i <= m/2; i++) {
		int t = (m - i) % m;
		if (i == t) {
			res += P[i] / 2;
			continue;
		}
		if (P[i] <= P[t] - U[t] * 2) {
			res += U[t] + P[i];
		}
		else if (P[i] - U[i] * 2 >= P[t]) {
			res += U[i] + P[t];
		}
		else {
			res += (P[i] + P[t]) / 2;
		}
	}
	printf("%d\n", res);
}