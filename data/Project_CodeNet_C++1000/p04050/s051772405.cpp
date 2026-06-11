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

	cin >> N >> M;
	vector<int>v(M);
	int edge = 0;
	bool odd = false;
	for (auto &i : v) {
		cin >> i;
		edge += i / 2;
		odd |= i & 1;
	}
	if (edge + N / 2 < N - 1) {
		cout << "Impossible\n";
		return 0;
	}
	if (!odd) {
		for (auto i : v)cout << i << " ";
		cout << endl;
		cout << v.size() + 1 << endl;
		cout << 1 << " ";
		for (int i = 0; i < M - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v.back() - 1 << endl;
		return 0;
	}
	if (v.size() == 1) {
		if (v[0] == 1) {
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 1 << endl;
			return 0;
		}
		cout << v[0] << endl;
		cout << 2 << endl;
		cout << v[0] - 1 << " " << 1 << endl;
		return 0;
		return 0;
	}
	if (accumulate(v.begin(), v.end(), 0) & 1) {
		for (int i = 0; i < M; i++) {
			if (v[i] & 1)swap(v[i], v[0]);
		}
		for (auto i : v)cout << i << " ";
		cout << endl;
		cout << v.size() << endl;
		cout << v[0] + 1 << " ";
		for (int i = 1; i < M - 1; i++)cout << v[i] << " ";
		cout << v.back() - 1 << endl;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		if (v[i] & 1) {
			swap(v[i], v[0]);
			for (int j = i + 1; j < M; j++) {
				if (v[j] & 1) {
					swap(v[j], v.back());
				}
			}
			break;
		}
	}
	for (auto i : v)cout << i << " ";
	cout << endl;
	cout << v.size() - 1 + (v.back() != 1) << endl;
	cout << v[0] + 1 << " ";
	for (int i = 1; i < M - 1; i++) {
		cout << v[i] << " ";
	}
	if (v.back() > 1)cout << v.back() - 1;
	cout << endl;
	return 0;
};