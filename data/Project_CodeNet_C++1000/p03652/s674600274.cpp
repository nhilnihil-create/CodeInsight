#include <bits/stdc++.h>
using namespace std;

int Rand(int x) {return rand() * rand() % x + 1;}

#define vi vector<int>
#define pii pair<int, int >
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long
const int INF = 0x3f3f3f3f, N = 305, M = 2000005, MOD = 1e9 + 7;

int a[N][N], vis[N], has[N];
int main() {
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= m;j ++) {
			cin >> a[i][j];
		}
		has[a[i][1]] ++;
	}
	int ans = INF; 
	while(1) {
		int maxn = 0, k = -1;
		for(int i = 1;i <= m;i ++) if(!vis[i] && has[i] > maxn) maxn = has[i], k = i;
		if(k == -1) break;
		ans = min(ans, maxn);
		for(int i = 1;i <= m;i ++) has[i] = 0; 
		vis[k] = 1;
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= m;j ++) if(!vis[a[i][j]]) {
				has[a[i][j]] ++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}