#include <iostream>
using namespace std;

int main() {

	char a, b;
	char res;
	do {
		cin >> a >> b;

	} while (a != 'H' && a != 'D' || b != 'H' && b != 'D' );

	if (a == 'H' && b == 'H') {
		res = 'H';
	}
	else if (a == 'H' && b == 'D') {
		res = 'D';
	}
	else if (a == 'D' && b == 'D') {
		res = 'H';
	}
	else {
		res = 'D';
	}

	cout << res << endl;
}