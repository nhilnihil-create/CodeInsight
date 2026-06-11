#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, M;
vector<vector<int>> A;
vector<int> s;

int solve() {
	vector<int> cnt(M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (s[A[i][j]]) {
			cnt[A[i][j]]++; break;
		}
	}
	auto r = max_element(cnt.begin(), cnt.end());
	s[r - cnt.begin()]--;
	return *r;
}

int main() {
	cin >> N >> M;
	int res = N;
	A.resize(N, vector<int>(M));
	s.resize(M, 1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> A[i][j], A[i][j]--;
	for (int i = 0; i < M-1; i++) {
		res = min(res, solve());
	}
	cout << res << endl;
}