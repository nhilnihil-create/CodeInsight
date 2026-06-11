#include <cstdio>
#include <deque>
using namespace std;

typedef long long i64;

i64 n;
int sz;
deque<int> a, b;

void build(i64 n) {
	if (n == 0) return;

	if (n % 2 == 1) {
		build(n / 2);
		++sz;
		a.push_back(sz);
		b.push_back(sz);
	} else {
		build(n - 1);
		++sz;
		a.push_back(sz);
		b.push_front(sz);
	}
}

int main() {
	scanf("%lld", &n);
	build(n);
	printf("%d\n", 2 * (int) a.size());

	for (int i : a) printf("%d ", i);
	for (int i : b) printf("%d ", i);
	puts("");
	return 0;
}