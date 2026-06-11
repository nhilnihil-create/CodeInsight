#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#define N 505

using namespace std;

int n;
int a[N * N], rem[N];

struct node {
	int pos, val;
}q[N];
inline bool cmp_node(node lhs, node rhs) { return lhs.pos < rhs.pos; }

queue<int> que;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		rem[i] = i - 1;
		cin >> q[i].pos, a[q[i].pos] = i;
		q[i].val = i;
	}
	
	sort(q + 1, q + 1 + n, cmp_node);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < q[i].val; ++j)
			que.push(q[i].val);
	
	for(int i = 1; i <= n * n; ++i) {
		if(a[i]) {
			if(rem[a[i]]) {
				puts("No");
				return 0;
			} else {
				for(int j = 1; j <= n - a[i]; ++j)
					que.push(a[i]);
			}
		} else {
			if(!que.empty()) {
				a[i] = que.front();
				--rem[a[i]];
				que.pop();
			} else {
				puts("No");
				return 0;
			}
		}
	}
	
	puts("Yes");
	for(int i = 1; i <= n * n; ++i)
		printf("%d%c", a[i], i == n * n ? '\n' : ' ');
	return 0;
}