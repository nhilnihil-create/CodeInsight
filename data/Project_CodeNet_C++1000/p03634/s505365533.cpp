#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	scanf("%d", &N);

	vector<vector<pair<int, int>>> edge(N + 1,
	                                    vector<pair<int, int>>());  // 1-Nを使う
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge[a].insert(edge[a].end(), make_pair(b, c));
		edge[b].insert(edge[b].end(), make_pair(a, c));
	}

	// for (int i = 1; i <= N; i++) {
	// 	cout << i << ":";
	// 	for (auto a : edge[i]) {
	// 		cout << a.first << " ";
	// 	}
	// 	cout << "\n";
	// }

	int Q, K;
	scanf("%d %d", &Q, &K);

	vector<pair<int, long long>> d_k(N + 1, make_pair(-1, -1));  // <親,距離 >
	stack<int> st;

	st.push(K);
	d_k[K].first = -1;
	d_k[K].second = 0;
	// cout << "size=" << st.size() << "\n";
	while (st.size() > 0) {
		int n = st.top();
		// cout << "pop " << n << "\n";
		st.pop();
		for (auto a : edge[n]) {
			if (a.first != d_k[n].first) {
				d_k[a.first].second = d_k[n].second + a.second;
				d_k[a.first].first = n;
				st.push(a.first);
				// cout << "push " << n << "\n";
			}
		}
	}

	// for (int i = 1; i <= N; i++) {
	// 	cout << i << ":" << d_k[i].first << " " << d_k[i].second << "\n";
	// }

	for (int i = 0; i < Q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		cout << d_k[x].second + d_k[y].second << "\n";
	}
	return 0;
}