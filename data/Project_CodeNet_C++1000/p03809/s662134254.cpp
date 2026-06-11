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
vector <long long> b[MAXN];
int value[MAXN];
bool halted;
void print(int pos) {
	for (unsigned i = 0; i < b[pos].size(); i++)
		cerr << b[pos][i] << ' ';
	cerr << endl;
}
long long work(int pos, int fa) {
	if (a[pos].size() == 1) return value[pos];
	long long sum = 0;
	for (unsigned i = 0; i < a[pos].size(); i++) {
		if (a[pos][i] == fa) continue;
		b[pos].push_back(work(a[pos][i], pos));
		sum += b[pos][b[pos].size() - 1];
	}
	long long tmp = sum - value[pos];
	long long ans = value[pos] - tmp;
	if (tmp < 0 || ans < 0) {
		halted = true;
		return 0;
	}
	long long maxnum = 0;
	for (unsigned i = 0; i < b[pos].size(); i++)
		maxnum = max(maxnum, b[pos][i]);
	if (sum - maxnum >= tmp) return ans;
	else {
		halted = true;
		return 0;
	}
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(value[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if (n == 2) {
		if (value[1] == value[2]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int root = 1;
	for (int i = 1; i <= n; i++)
		if (a[i].size() >= 2) {
			root = i;
			break;
		}
	if (work(root, 0) == 0 && !halted) printf("YES\n");
	else printf("NO\n");
	return 0;
}