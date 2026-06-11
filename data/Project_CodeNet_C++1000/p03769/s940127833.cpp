#include <bits/stdc++.h>
using namespace std;

long long n;
int tot;
deque<int> Queue;

void dfs(long long x) {
	if (x == 1) return;
	if (x & 1) dfs(x - 1), Queue.push_front(++tot);
	else dfs(x >> 1), Queue.push_back(++tot);
}

int main() {
	scanf("%lld", &n);
	dfs(n + 1);
	printf("%d\n", tot << 1);
	for (int i = 0; i < tot; ++i) printf("%d ", Queue[i]);
	for (int i = 1; i <= tot; ++i) printf("%d ", i);
}