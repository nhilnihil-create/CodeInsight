#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	if (a == 'H') {
		if (b == 'H')
			cout << 'H' << endl;
		else
			cout << 'D' << endl;
		return 0;
	}
	else {
		if (b == 'H')
			cout << 'D' << endl;
		else
			cout << 'H' << endl;
		return 0;
	}
}