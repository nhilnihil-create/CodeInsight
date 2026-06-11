#include <iostream>
using namespace std;

int main() {

	char s[19];

	cin >> s;
	
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ',') {
			s[i] = ' ';
		}
	}
	cout << s << endl;

	return 0;
}