#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	cout << a + b << endl;
	return 0;
}