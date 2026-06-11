#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e13;

int main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int> r(R);
	for(int i=0;i<R;i++) {
		cin >> r[i];
		r[i]--;
	}
	vector<vector<ll>> dist(N, vector<ll>(N, INF));
	for(int i=0;i<M;i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			for(int k=0;k<N;k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
	sort(r.begin(), r.end());
	ll ans = LLONG_MAX;
	do {
		ll tmp_ans = 0;
		int now = r[0];
		for(int i=1;i<R;i++) {
			int next = r[i];
			tmp_ans += dist[now][next];
			now = next;
		}
		ans = min(ans, tmp_ans);
	} while(next_permutation(r.begin(), r.end()));
	
	cout << ans << endl;
}