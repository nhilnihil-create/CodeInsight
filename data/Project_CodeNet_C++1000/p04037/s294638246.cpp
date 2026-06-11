#include <iostream>
#include <algorithm>

using i64 = long long;

const int N = 1000000 + 7;

int n;
int a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	std::sort(a + 1, a + n + 1, [](int a, int b) { return a > b; });
	for (int i = n; i; --i)
		b[i] = a[i] != a[i + 1] ? 1 : b[i + 1] ^ 1;
	for (int i = 1; i <= n; ++i)
		if (a[i + 1] < i + 1) {
			if (a[i] == i)
				printf(b[i] ? "Second" : "First");
			else
				printf((a[i] - i)  % 2 || (a[i + 1] == i && b[i + 1]) ? "First" : "Second");
			return 0;
		}
}
