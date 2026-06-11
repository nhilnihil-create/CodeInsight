#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
vector <int> a[MAXN];
int ans[MAXN];
void work(int pos, int fa) {
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] == fa) continue;
		else {
			work(a[pos][i], pos);
			ans[pos] ^= ans[a[pos][i]] + 1;
		}
}
int main() {
	int n; read(n);
	for (int i = 1; i < n; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1, 0);
	if (ans[1]) printf("Alice\n");
	else printf("Bob\n");
	return 0;
}