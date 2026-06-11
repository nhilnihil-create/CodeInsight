#include <bits/stdc++.h>

using namespace std;  

const int maxn = 1e5 + 10;

int n;
vector<int> e[maxn];
long long a[maxn];
bool dfs(int x, int fa) {
	if(e[x].size() == 1) return true;
	long long sum = 0, mx = 0;
	for(auto &it : e[x]) {
		int v = it;
		if(v == fa) continue;
		if(!dfs(v, x)) return false;
		sum += a[v];
		mx = max(mx, a[v]);
	}
	mx = min(sum - mx, sum / 2);
	long long tmp = sum - a[x];
	if(tmp < 0 || tmp > mx) return false;
	a[x] -= tmp;
	if(x == fa) return a[x] == 0;
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(n == 2) {
		a[1] == a[2] ? printf("YES\n") : printf("NO\n");
		return 0;
	}
	int pos = -1;
	for(int i = 1; i <= n; i++) {
		if(e[i].size() != 1) {
			pos = i;
			break;
		}
	}
	dfs(pos, pos) ? printf("YES\n") : printf("NO\n");
	return 0;
}