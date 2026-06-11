#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int cur, tot;
long long n;

deque<int> A, B;

void solve(long long n) {
	if(!n) return;
	if(n & 1) {
		solve(n >> 1);
		++cur, tot += 2;
		A.push_back(cur), B.push_back(cur);
	} else {
		solve(n - 1);
		++cur, tot += 2;
		A.push_back(cur), B.push_front(cur);
	}
	return;
}

int main() {
	scanf("%lld", &n);
	solve(n);
	printf("%d\n", tot);
	for(int i = 1; i <= tot / 2; ++i) {
		printf("%d ", A.front());
		A.pop_front();
	}
	for(int i = 1; i <= tot / 2; ++i) {
		printf("%d%c", B.front(), i == tot / 2 ? '\n' : ' ');
		B.pop_front();
	}
	return 0;
}