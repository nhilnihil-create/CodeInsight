#include <bits/stdc++.h>

using namespace std;

int n, m, d;

int main() {
	scanf("%d%d%d", &n, &m, &d);
	if (d % 2)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf((i + j) % 2 ? "R" : "Y");
			printf("\n");
		}
	else {
		d /= 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// printf("%d%d", i + j, i - j + m);
				if ((i + j) / 2 / d % 2 == 0) {
					if ((i - j + m) / 2 / d % 2 == 0)
						printf("R");
					else
						printf("Y");
				} else {
					if ((i - j + m) / 2 / d % 2 == 0)
						printf("G");
					else
						printf("B");
				}
			}
			printf("\n");
		}
	}
	return 0;
}