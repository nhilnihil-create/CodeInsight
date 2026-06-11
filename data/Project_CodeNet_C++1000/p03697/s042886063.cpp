#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a + b >= 10)
		cout << "error" << "\n";
	else
		cout << a + b << "\n";
}