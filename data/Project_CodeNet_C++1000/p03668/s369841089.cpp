#include <bits/stdc++.h>
using std::vector;
using std::pair;

using pii = pair<int, int>;
vector<int> G[100003];
int cnt[100003];
void go(int idx,int p) {
	
	for (auto &to : G[idx]) {
		if (p == to) continue;
		go(to, idx);
		cnt[idx] ^= cnt[to] + 1;
	}
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	go(1,1);
	if (cnt[1] == 0) printf("Bob");
	else printf("Alice");
}