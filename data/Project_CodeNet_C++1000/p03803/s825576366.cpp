#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A == 1) {
		if (B == 1) cout << "Draw" << endl;
		else cout << "Alice" << endl;
	}
	else if (B == 1) {
		if (A == 1) cout << "Draw" << endl;
		else cout << "Bob" << endl;
	}
	else if (A == B) cout << "Draw" << endl;
	else if (A < B) cout << "Bob" << endl;
	else if (A > B) cout << "Alice" << endl;
	return 0;
}