#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int K;
	cin >> s >> K;
	for (char& i : s) {
		if (i != 'a' && 'z' + 1 - i <= K) {
			K -= 'z' + 1 - i;
			i = 'a';
		}
	}
	s.back() = (s.back() - 'a' + K) % 26 + 'a';
	cout << s;
}