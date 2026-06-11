#include <bits/stdc++.h>
using namespace std;

int n, a;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() - (!(s.size()&1));

	return 0;
}