#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;

	string u = s + t;
	for (int i = 0; i < n; i++) {
	// printf("%d: %s %s\n", i, s.substr(i).c_str(), t.substr(0, n - i).c_str());
		if (s.substr(i) == t.substr(0, n - i)) {
			u = s.substr(0, i) + t;
			break;
		}
	}

	// cout << u << endl;
	cout << u.size() << endl;
	return 0;
}
