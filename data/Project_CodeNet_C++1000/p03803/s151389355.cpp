#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A == B) cout << "Draw" << endl;
	else {
		if (A == 1 || B == 1) cout << (A == 1 ? "Alice" : "Bob") << endl;
		else cout << (A > B ? "Alice" : "Bob") << endl;
	}
}