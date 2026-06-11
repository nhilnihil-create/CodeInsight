#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int cun = a + b + c;
	if (max(a, max(b, c)) == cun - max(a, max(b, c)))
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}