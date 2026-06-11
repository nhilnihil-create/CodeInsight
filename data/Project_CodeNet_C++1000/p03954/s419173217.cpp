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

//long long int N, M, K, H, W, L, R;
int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N * 2 - 1);
	for (auto &i : v)cin >> i;
	L = 2; R = N * 2 - 1;
	while (R - L > 1) {
		int mid = (R + L) / 2;
		auto w = v;
		for (auto &j : w)j = j >= mid;
		int maru = MOD;
		int batu = MOD;
		for (int j = 1; j < N * 2 - 1; j++) {
			if (w[j] == w[j - 1]) {
				if (w[j]) {
					maru = min(maru, abs(N - 1 - j));
					maru = min(maru, abs(N - 1 - j + 1));
				}
				else {
					batu = min(batu, abs(N - 1 - j));
					batu = min(batu, abs(N - 1 - j + 1));
				}
			}
		}
		if (maru == MOD && batu == MOD) {
			if (w[0])L = mid;
			else R = mid;
		}
		else {
			if (maru < batu)L = mid;
			else R = mid;
		}
	}
	cout << L << endl;
	return 0;
}