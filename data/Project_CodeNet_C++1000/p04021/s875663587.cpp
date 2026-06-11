#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/agc003/tasks/agc003_c

int n, ans;
pair<int, int> arr[100000];

int main() {
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		arr[i] = make_pair(a, i);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i += 2)
		if (arr[i].second & 1)
			ans++;
	cout << ans << endl;
}
