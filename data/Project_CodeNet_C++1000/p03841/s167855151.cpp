#include <bits/stdc++.h>
using namespace std;
int main()
{
	// freopen("AGC008-D.in", "r", stdin);
	int n;
	cin >> n;
	vector<int> arr(n), ans(n * n, -1), cnt(n, 0);
	copy(istream_iterator<int>(cin), istream_iterator<int>(), arr.begin());
	for_each(arr.begin(), arr.end(), [&] (int &x) { x--; });
	for (int i = 0; i < n * n; i++) {
		for (int j = 0; j < n && -1 == ans[i]; j++) {
			if (arr[j] == i) {
				ans[i] = j + 1;
			}
		}
		int pos = -1;
		for (int j = 0; j < n && -1 == ans[i]; j++) {
			if (i < arr[j] && cnt[j] < j) {
				if (pos == -1 || arr[j] < arr[pos]) {
					pos = j;
				}
			}
		}
		if (~pos) {
			cnt[pos]++;
			ans[i] = pos + 1;
		}
		for (int j = 0; j < n && -1 == ans[i]; j++) {
			if (arr[j] < i && cnt[j] != n - 1 && cnt[j] >= j) {
				cnt[j]++;
				ans[i] = j + 1;
			}
		}
		if (-1 == ans[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
