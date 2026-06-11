#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b) {
		if (b != c)
			cout << "2" << "\n";
		if (b == c)
			cout << "1" << "\n";
	}
	else if (b == c)
		cout << "2" << "\n";
	else if (a == c)
		cout << "2" << "\n";
	else
		cout << "3" << "\n";
}