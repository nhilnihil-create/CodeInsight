// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	string s; cin >> s;
	int n = s.length();
	cout << (n % 2 == (s[0] == s[n - 1]) ? "Second" : "First") << '\n';
	return 0;
}
