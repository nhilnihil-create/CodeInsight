#include <iostream>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	char ca = a.at(0) - 0x20;
	char cb = b.at(0) - 0x20;
	char cc = c.at(0) - 0x20;

	cout << ca << cb << cc << endl;

}