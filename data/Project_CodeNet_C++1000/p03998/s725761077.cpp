#include<iostream>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	char turn = 'a';
	while (1) {
		switch (turn) {
		case 'a':
			if (a == "") {
				cout << "A\n";
				return 0;
			}
			turn = a[0];
			a = a.substr(1, a.length() - 1);
			break;
		case 'b':
			if (b == "") {
				cout << "B\n";
				return 0;
			}
			turn = b[0];
			b = b.substr(1, b.length() - 1);
			break;
		case 'c':
			if (c == "") {
				cout << "C\n";
				return 0;
			}
			turn = c[0];
			c = c.substr(1, c.length() - 1);
			break;
		}
	}
}