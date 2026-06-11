#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;


int main(int argc, char** argv) {
    long long N, K;

    cin >> N >> K;

	vector<long long> a(N), a_sum(N + 1), sorted, unsorted;
	long long ans = 0;
	int n_th = int(sqrt(N)) + 1;

	for (int i = 0; i < N; i++) 
		cin >> a[i];

	for (int i = 1; i <= N; i++)
		a_sum[i] = a_sum[i - 1] + a[i - 1] - K;


	for (int i = 0; i <= N; i++) {
		// ソート済の部分は2分探索で
		ans += upper_bound(sorted.begin(), sorted.end(), a_sum[i]) - sorted.begin();

		// ソートしていない部分はナイーブに
		for (int j = 0; j < unsorted.size(); j++)
			ans += a_sum[i] >= unsorted[j];

		unsorted.push_back(a_sum[i]);

		if (unsorted.size() >= n_th) {
			sort(unsorted.begin(), unsorted.end());
			auto middle = sorted.insert(sorted.end(), unsorted.begin(), unsorted.end());
			inplace_merge(sorted.begin(), middle, sorted.end());
			unsorted.clear();
		}

	}

	cout << ans << endl;
}