#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<list>
#include<queue>
#include<string.h>
#include<functional>
#include<stack>
#include<deque>
#include<string>
#include<limits.h>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<int>r[100000];
int DFS(int p, int a) {
	int b = 0;
	for (int c : r[a]) {
		if (c != p) {
			b ^= DFS(a, c)+1;
		}
	}
	return b;
}
signed main() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		x--; y--;
		r[x].push_back(y);
		r[y].push_back(x);
	}
	if (DFS(-1, 0)) {
		puts("Alice");
	}
	else {
		puts("Bob");
	}
}