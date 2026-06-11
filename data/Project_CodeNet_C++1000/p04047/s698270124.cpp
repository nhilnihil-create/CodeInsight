#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, L;
	cin >> N;
	int total = 0;
	vector<int> vec(2 * N);
	for (int i = 0; i < 2 * N; i++) {
		cin >> L;
		vec.at(i) = L;
	}
	sort(vec.begin(), vec.end());
	for (int j = 0; j < 2 * N; j += 2) {
		total += vec.at(j);
	}
	cout << total << endl;
}