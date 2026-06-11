#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (2 * b - a - c ? "NO" : "YES");
	return 0;
}