#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
typedef pair<int, int> P;
int x[501];
int cnt[500];
int ans[500 * 500 + 1];
int main() {
	int N;
	cin >> N;
	vector<P> order;
	for (int i = 1; i <= N; i++) {
		cin >> x[i];
		ans[x[i]] = i;
		order.emplace_back(x[i], i);
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < N; i++) {
		cnt[i] = order[i].second;
		if (i > 0) cnt[i] += cnt[i - 1];
		if (cnt[i] > order[i].first) {
			cout << "No" << endl;
			return 0;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		cnt[i] = N - order[i].second + 1;
		if (i + 1 < N) cnt[i] += cnt[i + 1];
		if (cnt[i] > N*N - order[i].first + 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	priority_queue < int, vector<int>, greater<int>> Q1;
	for (int i = 1; i <= N * N; i++) {
		if (ans[i] == 0) {
			Q1.push(i);
		}
		else {
			for (int j = 0; j < ans[i] - 1; j++) {
				ans[Q1.top()] = ans[i];
				Q1.pop();
			}
		}
	}
	priority_queue<int> Q2;
	while (!Q1.empty()) {
		Q2.push(Q1.top());
		Q1.pop();
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N - order[i].second; j++) {
			ans[Q2.top()] = order[i].second;
			Q2.pop();
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= N * N; i++) cout << ans[i] << " ";
	cout << endl;
}
