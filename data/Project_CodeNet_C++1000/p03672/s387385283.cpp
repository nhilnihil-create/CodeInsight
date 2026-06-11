#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	string s;
	cin >> s;
	if ((int) s.size() & 1) {
		while (1) {
			s.erase(s.end() - 1);
			string left = s.substr(0, (int) s.size() / 2);
			string right = s.substr((int) s.size() / 2, (int) s.size() / 2);
			if (left == right) {
				return printf("%d\n", (int) s.size()), 0;
			}
		}
	} else {
		while (1) {
			s.erase(s.end() - 2, s.end());
			string left = s.substr(0, (int) s.size() / 2);
			string right = s.substr((int) s.size() / 2, (int) s.size() / 2);

			if (left == right) {
				return printf("%d\n", (int) s.size()), 0;
			}
		}
	}
}

