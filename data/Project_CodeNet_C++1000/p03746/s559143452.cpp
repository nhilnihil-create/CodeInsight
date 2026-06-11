#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define M 2000000000
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200100
vector<int>e[N];
int n, m;
bool used[N];
vector<int>a;
vector<int>b;
vector<int>c;
void dfs(int k) {
	used[k] = true;
	a.push_back(k);
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs(e[k][i]);
			return;
		}
	}
	return;
}
void dfs2(int k) {
	used[k] = true;
	b.push_back(k);
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs2(e[k][i]);
			return;
		}
	}
	return;
}

int main(void) {
	scanf("%d %d", &n, &m);
	int x, y, z;
	int ans = 0;
	f(i, m) {
		scanf("%d %d", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
	}
	f(i, n)used[i] = false;
	dfs(0);
	dfs2(0);
	x = a.size();
	for (int i = x - 1; i > 0; i--)c.push_back(a[i]);
	x = b.size();
	f(i, x)c.push_back(b[i]);
	x = c.size();
	printf("%d\n", x);
	f(i, x - 1)printf("%d ", c[i]+1);
	printf("%d\n", c[x - 1]+1);
	return 0;
}