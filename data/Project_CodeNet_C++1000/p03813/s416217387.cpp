#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	if (x < 1200) {
		cout << "ABC" << endl;

	}
	else if(1200 <= x && x <= 3000){
		cout << "ARC" << endl;
	}
}