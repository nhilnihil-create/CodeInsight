#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N, K;
	cin >> N >> K;

	vector<int> a;
	for (int i = 0; i < N; i++) {
		int ai;
		cin >> ai;
		if (ai >= K) continue;
		a.push_back(ai);
	}

	sort(begin(a), end(a));

	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		int discard = a[i];
		int sum = 0;
		for (int j = a.size() - 1; j >= 0; j--) {
			if (i == j) continue;
			if (sum + a[j] >= K) continue;
			sum += a[j];
		}
		if (sum + discard < K) ans++;
	}

	cout << ans << endl;

	return 0;
}