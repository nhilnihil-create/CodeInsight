#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 7;

LL a[N], b[N], c[N];
int f[N];
bool vis[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];
	for (int i = 2; i <= n; i++) f[i] = i;
	int m; long long k;
	scanf("%d%lld", &m, &k);
	for (int i = 1; i <= m; i++){
		int x; scanf("%d", &x);
		swap(f[x], f[x + 1]);
	}
	for (int i = 2; i <= n; i++){
		if (!vis[i]){
			vector<int > v;
			int j = i;
			while (!vis[j]){
				v.push_back(j);
				vis[j] = true;
				j = f[j];
			}	
			int len = v.size(), p = k % len;
			for (int j = 0; j < len; j++){
				c[v[j]] = b[v[(j + p) % len]];
			}
		}
	}
	LL t = a[1];
	for (int i = 2; i <= n; i++){
		t += c[i];
		a[i] = t;
	}
	for (int i = 1; i <= n; i++) printf("%lld ", a[i]);

	return 0;
}