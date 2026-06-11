#include <iostream>
using namespace std;

int main() {

	int a, b;
	string s;
	
	do {
		cin >> a >> b;

	} while (a < 1 || a > 13 || b < 1 || b > 13);
	
	

	if (a > b && a != 1) {
		s = "Alice";
		if (b == 1) {
			s = "Bob";
		}
		
	}
	else if (a < b) {
		s = "Bob";
		if (a == 1) {
			s = "Alice";
		}
		
	}
	else {
		s = "Draw";
		
	}

	cout << s << endl;
}