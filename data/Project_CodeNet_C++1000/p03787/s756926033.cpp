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
int n, m;
vector <int> a[MAXN];
bool visited[MAXN], colour[MAXN], circle;
long long cnt[3];
void work(int pos, int fa) {
	visited[pos] = true; colour[pos] = !colour[fa];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (!visited[a[pos][i]]) work(a[pos][i], pos);
		else if (colour[pos] == colour[a[pos][i]]) circle = true;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		circle = false; work(i, 0);
		if (a[i].size()) {
			if (circle) cnt[1]++;
			else cnt[2]++;
		} else cnt[0]++;
	}
	long long ans = cnt[0] * cnt[0] + cnt[0] * 2 * (n - cnt[0]) + cnt[2] * cnt[2] * 2 + cnt[1] * (cnt[2] * 2 + cnt[1]);
	cout << ans << endl;
	return 0;
}