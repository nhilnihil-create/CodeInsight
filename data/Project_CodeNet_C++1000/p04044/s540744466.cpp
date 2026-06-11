#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	vector<string>s(n); for (auto&& x : s)cin >> x;
	sort(s.begin(), s.end());
	for (auto&& x : s)cout << x;
	cout << endl;

	return 0;
}