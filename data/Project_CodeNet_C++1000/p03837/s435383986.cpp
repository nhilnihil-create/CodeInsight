#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define endl '\n'
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>dis(n, vector<int>(n, 1e8));
	vector<int>s(m), d(m), l(m);
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> d[i] >> l[i];
		s[i]--, d[i]--;
		dis[s[i]][d[i]] = l[i];
		dis[d[i]][s[i]] = l[i];
	}
	for (int i = 0; i < n; i++)dis[i][i] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (l[i] != dis[s[i]][d[i]])ans++;
	}
	cout << ans << endl;
}




