#include<cstdio>
#include<vector>
using namespace std;
int main(void) {
	int n, m;
	vector<int>a,aa, b;
	int x, y, z;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		a.push_back(x);
	}
	x = 0;
	y = 0;
	z = 0;
	for (int i = 0; i < m; i++) {
		if (a[i] % 2 == 1) {
			if (x == 0) {
				y = a[i];
				x++;
			}
			else {
				z = a[i];
				x++;
			}
		}
	}
	if (x > 2) {
		printf("Impossible\n");
		return 0;
	}
	if (m == 1) {
		printf("%d\n", a[0]);
		if (n == 1) {
			printf("1\n");
			printf("1\n");
			return 0;
		}
		printf("2\n");
		printf("1 %d\n", n - 1);

		return 0;
	}
	if (y != 0) {
		aa.push_back(y);
		b.push_back(y);
	}
	for (int i = 0; i < m; i++) {
		if (a[i] % 2 == 0) {
			aa.push_back(a[i]);
			b.push_back(a[i]);
		}
	}
	if (z != 0) {
		aa.push_back(z);
		if (z > 1)b.push_back(z);
		else b[b.size() - 1]++;
	}
	b[0]++;
	b[b.size() - 1]--;
	for (int i = 0; i < aa.size(); i++) {
		printf("%d", aa[i]);
		if (i < aa.size() - 1)printf(" ");
		else printf("\n");
	}
	printf("%d\n", b.size());
	for (int i = 0; i < b.size(); i++) {
		printf("%d", b[i]);
		if (i < b.size() - 1)printf(" ");
		else printf("\n");
	}

	return 0;
}