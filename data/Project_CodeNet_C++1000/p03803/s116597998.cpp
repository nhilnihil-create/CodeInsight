#include<iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b;
	if ((a < b && a > 1) || (a == 13 && b == 1)) cout << "Bob" << endl;
	else if (a != b) cout << "Alice" << endl;
	else cout << "Draw" << endl;
	return 0;
}