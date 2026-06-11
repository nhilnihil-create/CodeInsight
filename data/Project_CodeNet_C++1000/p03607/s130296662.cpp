#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int i = 0;
	while (i < v.size()) {
		int p = v.at(i);
		int c = 0;
		while ((i < v.size()) && (v.at(i) == p)) {
			c++;
			i++;
		}
		ans += c % 2;
	}

	cout << ans << endl;
}
