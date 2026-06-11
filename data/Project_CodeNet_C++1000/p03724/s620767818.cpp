#include <iostream>
using namespace std;
int a[100005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int s, t;
		scanf("%d%d", &s, &t);
		a[s - 1]++, a[t - 1]++;
	}
	for (int i = 0; i < 100005; i++) {
		if (a[i] % 2) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}