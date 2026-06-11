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
#define N 2000100
vector<int>e[N];
int n, m;
bool used[N];
bool used2[N];
int a[N];
int b[N];
void dfs(int k, int d) {
	used[k] = true;
	if (d == 0)return;
	f(i, e[k].size()) {
		if (!used[e[k][i]]) {
			dfs(e[k][i], d - 1);
		}
	}
	return;
}

int main(void) {
	scanf("%d %d", &n, &m);
	int x, y, z;
	int ans = 0;
	f(i, n - 1) {
		scanf("%d %d", &x, &y);
		e[x - 1].push_back(y - 1);
		e[y - 1].push_back(x - 1);
		a[i] = x - 1;
		b[i] = y - 1;
	}
	if (m % 2 == 0) {
		f(ii, n) {
			f(i, n)used[i] = false;
			dfs(ii, (m/2));
			x = 0;
			f(i, n)if (used[i])x++;
			ans = max(ans, x);
		}
	}
	else {
		f(ii, n - 1) {
			f(i, n)used2[i] = false;
			f(i, n)used[i] = false;
			dfs(a[ii], (m / 2));
			f(i, n)if (used[i])used2[i] = true;
			f(i, n)used[i] = false;
			dfs(b[ii], (m / 2));
			f(i, n)if (used[i])used2[i] = true;
			x = 0;
			f(i, n)if (used2[i])x++;
			ans = max(ans, x);
		}
	}
	printf("%d\n", n - ans);
}