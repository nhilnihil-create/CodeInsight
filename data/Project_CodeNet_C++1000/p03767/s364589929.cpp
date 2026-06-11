#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	long long int N, max = 0, TMP;
	vector<long long int> a;

	cin >> N;
	for (int i = 0; i < (3 * N); i++) {
		cin >> TMP;
		a.push_back(TMP);
	}
	sort(a.rbegin(), a.rend());

	for (int i = 0; i < N; i++) {
		max += a[i * 2 + 1];
	}
	cout << max << endl;

	return 0;
}