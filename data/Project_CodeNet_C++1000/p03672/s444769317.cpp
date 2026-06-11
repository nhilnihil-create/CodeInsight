#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main() {
	string s, a, b;
	cin >> s;
	while (1) {
		s.erase(s.begin() + s.size() - 1);
		a = s.substr(0, s.size() / 2);
		b = s.substr(s.size() / 2, s.size());
		if (s.size() % 2 == 0) {
			if (a == b) {
				break;
			}
		}
	}
	cout << s.size();
	return 0;
}