#include <stdio.h>
#include <algorithm>

using namespace std;

int a[100001], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	bool prev = false;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (prev) {
			swap(a[i - 1], a[i]);
			res++;
			prev = false;
		}
		if (a[i] == i) prev = true;
	}
	res += prev;
	printf("%d\n", res);
	return 0;
}