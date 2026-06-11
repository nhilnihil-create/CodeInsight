#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>num(M);
	for (int i = 0; i < M; i++) {
		cin >> num[i];
		if (num[i] % 2) {
			K++;
		}
	}
	if (K > 2) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < M; i++) {
		if (num[i] % 2) {
			swap(num[i], num[0]);
			break;
		}
	}
	for (int i = M - 1; i >= 0; i--) {
		if (num[i] % 2) {
			swap(num[i], num[M - 1]);
			break;
		}
	}
	for (int i = 0; i < M; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	if (M == 1) {
		if (num[0] == 1) {
			cout << 1 << endl << 1 << endl;
			return 0;
		}
		cout << 2 << endl;
		cout << num[0] - 1 << " " << 1 << endl;
		return 0;
	}
	if (num[0] == 1) {
		cout << M - 1 << endl;
	}
	else {
		cout << M << endl;
	}
	num[0]--;
	num[M - 1]++;
	for (auto i : num) {
		if (i) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
