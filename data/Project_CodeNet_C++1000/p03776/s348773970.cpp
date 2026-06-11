
// D - Maximum Average Sets

// 組み合わせを計算する解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int N_MAX = 50;

ll comb[N_MAX + 1][N_MAX + 1];

void init_comb() {
	comb[0][0] = 1;
	for (int i=1; i<=N_MAX; i++) {
		for (int j=0; j<=i; j++) {
			comb[i][j] += comb[i-1][j];
			if (j > 0) comb[i][j] += comb[i-1][j-1];
		}
	}
}

long double v[51];
map<long double, int> v_cnt; // vの各値の個数
map<long double, int> v_first_appear_idx; // 降順ソート後にvの各値が最初に出てくるindex
vector<int> last_v_idx_list; // 平均が最大となるときの最後に選んだvのindex

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	for (int i=0; i<N; i++) {
		cin >> v[i];
		v_cnt[v[i]]++;
	}

	sort(v, v+N, greater<long double>());

	// vの各値が最初に出てくるindexを求めておく
	v_first_appear_idx[v[0]] = 0;
	for (int i=1; i<N; i++) {
		if (v[i] != v[i-1]) {
			v_first_appear_idx[v[i]] = i;
		}
	}

	// ---- 平均値の最大値を求める ---- //
	long double total = 0;
	long double max_mean = 0;
	for (int i=0; i<N; i++) {
		total += v[i];
		if (i+1 >= A && i+1 <= B) {
			long double tmp_mean = total / (i+1);
			if (tmp_mean > max_mean) {
				max_mean = tmp_mean;
				last_v_idx_list.clear();
				last_v_idx_list.push_back(i);
			} else if (tmp_mean == max_mean) {
				last_v_idx_list.push_back(i);
			}
		}
	}

	// ---- 場合の数を求める ---- //
	init_comb();
	ll num_ways = 0;
	for (int last_v_idx : last_v_idx_list) {
		long double last_v = v[last_v_idx];
		int num_selected_last_v = last_v_idx - v_first_appear_idx[last_v] + 1;
		num_ways += comb[v_cnt[last_v]][num_selected_last_v];
	}

	cout << fixed << setprecision(10);
	cout << max_mean << endl;
	cout << num_ways << endl;

	return 0;
}