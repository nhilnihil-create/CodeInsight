#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> a, b;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int s; cin >> s;
		sum += s;
		if (s % 10 == 0) a.push_back(s);		
		else b.push_back(s);
		}
	sort(b.begin(), b.end());
	int cnt = b.size();
	if (sum % 10 == 0) {
		if (cnt == 0) {
			cout << 0 << endl;
		}
		else cout << sum - b[0] << endl;
	}
	else cout << sum << endl;
	return 0;
}