#include<cstdio>
#include<vector>
#include<queue>
#define INF 10000
#define pp pair<int,int>
using namespace std;
vector<vector<int> > ar;
queue<pair<int,int> > q;
int n,root,k;
bool chk[2005];
int centeris(int x,int x2) {
	int i;
	for (i = 1; i <= n; i++) chk[i] = false;
	chk[x] = true; chk[x2] = true;
	q.push(pp(0, x));
	if (x2 > 0) q.push(pp(0, x2));
	int ret = 0;
	int len;
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		x = p.second; len = p.first;
		if (len > k) ret++;
		for (int next : ar[x]) {
			if (chk[next]) continue;
			chk[next] = true;
			q.push(pp(len + 1, next));
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n,&k);
	ar.resize(n + 1);
	int i;
	for (i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int ans = INF;
	if (k % 2 == 0) {
		k /= 2;
		for (i = 1; i <= n; i++) {
			int res = centeris(i, 0);
			if (ans > res) ans = res;
		}
	}
	else {
		k = (k - 1) / 2;
		for (i = 1; i <= n; i++) {
			for (int next : ar[i]) {
				int res = centeris(i, next);
				if (ans > res) ans = res;
			}
		}
	}
	printf("%d", ans);
	return 0;
}