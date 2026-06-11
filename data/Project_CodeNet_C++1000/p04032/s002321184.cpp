#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e6 + 5;
const int inf = 1e9 + 7;

vector <int> v[30];

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size() - 2; i ++) {
		if (s[i] == s[i + 1] || s[i] == s[i + 2] || s[i + 1] == s[i + 2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	if (s.size() == 2 && s[0] == s[1]) {
		cout << "1 2" << endl;
		return 0;
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}

