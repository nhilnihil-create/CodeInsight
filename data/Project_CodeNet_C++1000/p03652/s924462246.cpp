#include <bits/stdc++.h>
#define mkp make_pair
typedef long long ll;
using namespace std;
const char sp = ' ';
int N, M, res, A[300][300], c[300];
bool b[300];


int main() {
	cin >> N >> M;
	res = 0xE869120;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
			--A[i][j];
		}
	}
	for (int i = 0; i < M; ++i) {
		b[i] = true;
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < M; ++j) {
			c[j] = 0;
		}
		for (int j = 0; j < N; ++j) {
			for (int k = 0;; ++k) {
				if (b[A[j][k]]) {
					++c[A[j][k]];
					break;
				}
			}
		}
		pair<int, int> MAX = mkp(-1, -1);
		for (int j = 0; j < M; ++j) {
			MAX = max(MAX, mkp(c[j], j));
		}
		res = min(res, MAX.first);
		b[MAX.second] = false;
	}
	cout << res << endl;
}