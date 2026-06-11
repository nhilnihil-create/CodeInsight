#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << 1 + (a != b) + (a != c && b != c) << endl;
}
