#include <iostream>
using namespace std;

int main() {
	string s;
	int K;
	cin >> s >> K;
	for (char& c : s) {
		if (c == 'a') continue;
		if ('z' - c + 1 <= K) {
			K -= 'z' - c + 1;
			c = 'a';
		}
	}
	K %= 26;
	while (K > 0) {
		s.back() = (s.back() == 'z' ? 'a' : s.back() + 1);
		K--;
	}
	cout << s << endl;
}
