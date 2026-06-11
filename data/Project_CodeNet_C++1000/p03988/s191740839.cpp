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
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	int radius = 0;
	for (int i = 0; i < N; i++) {
		cin >> M;
		radius = max(radius, (int)M);
		v[M]++;
	}
	if (N > 2 && radius == 1) {
		cout << "Impossible\n";
		return 0;
	}
	if (radius & 1) {
		for (int i = (radius + 1) / 2; i <= radius; i++) {
			if (v[i] < 2) {
				cout << "Impossible\n";
				return 0;
			}
		}
		if (v[radius / 2 + 1] != 2) {
			cout << "Impossible\n";
			return 0;
		}
		for (int i = 0; i < (radius + 1) / 2; i++) {
			if (v[i]) {
				cout << "Impossible\n";
				return 0;
			}
		}
		cout << "Possible\n";
		return 0;
	}
	for (int i = radius / 2 + 1; i <= radius; i++) {
		if (v[i] < 2) {
			cout << "Impossible\n";
			return 0;
		}
	}
	if (v[radius / 2] != 1) {
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < radius / 2; i++) {
		if (v[i]) {
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	return 0;
}