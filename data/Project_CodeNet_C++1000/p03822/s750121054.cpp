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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000
vector<int>e[N];

int solve(int x) {
	if (e[x].size() == 0)return 0;
	vector<int>b;
	int y;
	f(i, e[x].size()) {
		y = solve(e[x][i]);
		b.push_back(y);
	}
	sort(b.begin(), b.end(), greater<int>());
	y = 0;
	f(i, b.size()) {
		y = max(b[i] + i + 1, y);
	}
	return y;
}


int main() {
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n-1) {
		scanf("%d", &x);
		e[x - 1].push_back(i + 1);
	}
	ans = solve(0);

	printf("%d\n", ans);


	return 0;
}