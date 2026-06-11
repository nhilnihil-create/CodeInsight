#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	bool No=false, We=false, So=false, Ea=false;
	for (char c : S) {
		if (c == 'N') No = true;
		if (c == 'S') So = true;
		if (c == 'W') We = true;
		if (c == 'E') Ea = true;
	}
	cout << (No == So && We == Ea ? "Yes" : "No") << endl;
}