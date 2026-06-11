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
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;
const long double EPS = 1e-7;

long long int N, M, K, H, W, L, R;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	int even = 0;
	for (auto &i : v) {
		cin >> i;
		if (i % 2 == 0)even++;
	}
	if (even % 2) {
		cout << "First\n";
		return 0;
	}
	int odd = 0;
	for (auto i : v) {
		if (i % 2)odd = i;
	}
	if (even % 2 == 0 && (even != N - 1 || (even == N - 1 && odd == 1))) {
		cout << "Second\n";
		return 0;
	}
	int bag = v[0] - (v[0] % 2);
	for (auto &i : v) {
		if (i % 2)i--;
		bag = gcd(bag, i);
	}
	for (auto &i : v)i /= bag;
	string ans[2] = { "First","Second" };
	int cnt = 0;
	while (1) {
		cnt++;
		even = 0;
		for (auto i : v)if (i % 2 == 0)even++;
		if (even % 2) {
			cout << ans[cnt % 2] << endl;
			return 0;
		}
		odd = 0;
		for (auto i : v)if (i % 2)odd = i;
		if (even % 2 == 0 && (even != N - 1 || (even == N - 1 && odd == 1))) {
			cout << ans[(cnt + 1) % 2] << endl;
			return 0;
		}
		bag = v[0] - (v[0] % 2);
		for (auto &i : v) {
			if (i % 2)i--;
			bag = gcd(bag, i);
		}
		for (auto &i : v)i /= bag;
	}
	return 0;
}