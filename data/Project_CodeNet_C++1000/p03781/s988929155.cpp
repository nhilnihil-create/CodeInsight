#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
	a[0] = 0;
	for (int i = 1; i < 100005; ++i) {
		a[i] = i + a[i - 1];
	}
	int x;
	scanf("%d", &x);
	for (int i = 0; i < 100005; ++i)
	{
		if (x <= a[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}