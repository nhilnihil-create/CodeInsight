#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, T, A, MIN;
	map<int, int> mp;
	cin >> N >> T >> MIN;
	for (int i = 1; i < N; i++) {
		cin >> A;
		mp[A - MIN]++;
		MIN = min(MIN, A);
	}
	auto it = mp.end();
	it--;
	cout << it->second;
}