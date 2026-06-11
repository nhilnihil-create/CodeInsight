#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
int A[100];
int main() {
	int N, M;
	cin >> N >> M;
	if (N == 1) {
		cout << 1 << endl;
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if (M == 1) {
		cout << N << endl;
		cout << 2 << endl;
		cout << N - 1 << " " << 1 << endl;
		return 0;
	}
	vector<int> odd;
	for (int i = 0; i < M; i++) {
		cin >> A[i];
		if (A[i] % 2) odd.push_back(i);
	}
	if (odd.size() > 2) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (odd.size() >= 1) swap(A[0], A[odd[0]]);
	if (odd.size() >= 2) swap(A[M - 1], A[odd[1]]);
	for (int i = 0; i < M; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	if (A[0] > 1) {
		cout << M << endl;
		cout << A[0] - 1 << " ";
	}
	else {
		cout << M - 1 << endl;
	}
	for (int i = 1; i < M; i++) {
		if (i == M - 1) cout << A[i] + 1 << " ";
		else cout << A[i] << " ";
	}
	cout << endl;
}
