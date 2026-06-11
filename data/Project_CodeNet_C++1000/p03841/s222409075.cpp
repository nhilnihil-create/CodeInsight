#include <iostream>
#include <algorithm>
using namespace std;

const int N = 505;

pair <int, int> b[N];
int cnt[N];
int a[N * N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i].first;
		b[i].second = i;
		a[b[i].first] = i;
	}
	sort(b + 1, b + n + 1);
	int t = 1, p = 1;
	for (int i = 1; i <= n * n; i++) {
		if (a[i]) {
			cnt[a[i]]++;
			if (cnt[a[i]] != a[i]) {
				cout << "No";
				return 0;
			}
			continue;
		}
		while (t <= n && cnt[b[t].second] >= b[t].second - 1) {
			t++;
		}		
		if (t <= n) {
			a[i] = b[t].second;
			cnt[a[i]]++;
		}
		else {
			while (cnt[b[p].second] == n) {
				p++;
			}
			a[i] = b[p].second;
			cnt[b[p].second]++;
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n * n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
