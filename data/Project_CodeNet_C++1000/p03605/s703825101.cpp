#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int n;
	cin>> n;
	if (n / 10 == 9 || n % 10 == 9)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}