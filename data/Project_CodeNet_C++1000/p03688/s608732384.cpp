#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	vector<int> cnt;
	cnt.push_back(1);
	for (int i = 1; i < n; i++) {
		if (v[i] != v[i - 1]) { 
			cnt.push_back(1);
			if (v[i] != v[i - 1] + 1) {
				cout << "No";
				return 0;
			}
		}
		else
			cnt.back()++;
	}
	if (cnt.size() > 2 || v.back() > n - 1) {
		cout << "No";
		return 0;
	}
	if (cnt.size() == 1 && (v.back() == n - 1 || v.back() <= n / 2)) {
		cout << "Yes";
		return 0;
	}
	if (cnt.size() == 2 && (v.back() > cnt[0] && v.back() <= cnt[0] + cnt[1] / 2)) {
		cout << "Yes";
		return 0;
	}
	cout << "No";		
	return 0;
}
