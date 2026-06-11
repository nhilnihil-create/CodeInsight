
// D - Candidates of No Shortest Paths

// Warshall-Floyd法で全点対間最短経路の距離を求めた後に
// 頂点 i と頂点 j を結ぶ辺が頂点 s から頂点 t への最短経路に含まれるとき
// min_dist(s, i) + edge(i, j) + min_dist(j, t) = min_dist(s, t)
// であることを利用する解法
// 計算量: O(MN^2) （より計算量の少ない方法あり）

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 922337203685477580;
// const ll MOD = 1e9 + 7;

const int N_MAX = 100;
const int M_MAX = 1000;
const ll INF = 1000000;

ll d[N_MAX][N_MAX]; // d[i][j] : 頂点iから頂点jへの最小コスト
int a[M_MAX], b[M_MAX], c[M_MAX]; // 辺の情報

void Warshall_Floyd(ll d[N_MAX][N_MAX], int n) {
	for (int k=0; k<n; k++) {
		for (int i=0; i<n; i++) {
			if (d[i][k] == INF) continue;
			for (int j=0; j<n; j++) {
				if (d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	// 自分自身への最小コストを0、それ以外をINFで初期化
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			d[i][j] = ((i == j) ? 0 : INF);
		}
	}

	for (int i=0; i<M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--;
		b[i]--;
		d[a[i]][b[i]] = c[i];
		d[b[i]][a[i]] = c[i];
	}

	Warshall_Floyd(d, N);

	// 条件を満たす辺の数をカウント
	int ans = 0;
	for (int i=0; i<M; i++) {
		bool is_included = false; // 最短経路に含まれるかどうか
		for (int s=0; s<N; s++) {
			for (int t=0; t<N; t++) {
				if (d[s][a[i]] + c[i] + d[b[i]][t] == d[s][t]) {
					is_included = true;
				}
			}
		}

		if (!is_included) ans++;
	}

	cout << ans << endl;

	return 0;
}
