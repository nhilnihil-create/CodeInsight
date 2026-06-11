#include <bits/stdc++.h>
using namespace std;


int main() {
	string s;
	cin >> s;
	vector<int> counter(26,0);

	for (auto i = 0; i < s.size(); i++) {
		int idx = int(s.at(i)-'a');
		counter.at(idx) += 1;
	}

	for (auto i = 0; i < counter.size(); i++) {
		if (counter.at(i) % 2 != 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
