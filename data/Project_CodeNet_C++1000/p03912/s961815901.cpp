#include <bits/stdc++.h>
using namespace std;

const int maxN = 100010;
vector<int> p[maxN];
int a[maxN];
int c[maxN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		c[a[i] % m]++;
	}
	sort(a, a + n);
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[i] == a[j]) j++;
		p[a[i] % m].push_back(j - i);
	}
	int ans = 0;
	for (int i = 1; i < m / 2; i++) {
		int u = i, v = m - u;
		a[u] = a[v] = min(c[u], c[v]);
		ans += a[u];
	}
	ans += c[0] / 2;
	if (m % 2 == 0){
		a[m/2]=c[m/2]/2*2;
		ans += c[m / 2] / 2;
	}
	else {
		int u = m / 2, v = m - m / 2;
		a[u] = a[v] = min(c[m / 2], c[m - m / 2]);
		ans += a[u];
	}
	for (int i = 1; i < m; i++) {
		int le=c[i]-a[i];
		for(int j=0;j<p[i].size();j++){
			if(p[i][j]>=2 && le>=2){
				int tmp=min(le/2,p[i][j]/2);
				le-=2*tmp;
				ans+=tmp;
			}
			if(le<=1)break;
		}
	}
	printf("%d\n", ans);
	return 0;
}