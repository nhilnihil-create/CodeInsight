#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int >, greater<int > > q;
int ans = 0;

int main() {
	for (int i = 1; i <= 3; ++i) {
		int t;
		scanf("%d", &t);
		q.push(t);
	}
	ans += q.top(); q.pop(); ans += q.top();
	printf("%d\n", ans);
	return 0;
}