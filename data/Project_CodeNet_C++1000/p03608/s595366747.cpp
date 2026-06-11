
// D - joisino's travel

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 200;
const ll INF = 9223372036854775807;

int N, M, R;
ll d[MAX][MAX]; // d[i][j] : 頂点iから頂点jへの最小コスト


void Warshall_Floyd() {
	for (int k=0; k<N; k++) {
		for (int i=0; i<N; i++) {
			if (d[i][k] == INF) continue;
			for (int j=0; j<N; j++) {
				if (d[k][j] == INF) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	cin >> N >> M >> R;

	vector<int> r_list;
	vector<int> indices;
	int r;
	for (int i=0; i<R; i++) {
		cin >> r;
		r--;
		r_list.push_back(r);
		indices.push_back(i);
	}

  // 自分自身への最小コストを0、それ以外をINFで初期化
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			d[i][j] = ((i == j) ? 0 : INF);
		}
	}

  // 辺の情報を与える
	int A, B, C;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> C;
		A--;
		B--;
		d[A][B] = C;
		d[B][A] = C;
	}

	Warshall_Floyd();

	ll ans = INF;
	do {
		ll total_dist = 0;
		for (int i=0; i<R-1; i++) {
			total_dist += d[r_list[indices[i]]][r_list[indices[i+1]]];
		}
		ans = min(ans, total_dist);
	} while (next_permutation(indices.begin(), indices.end()));

	cout << ans << endl;

	return 0;
}