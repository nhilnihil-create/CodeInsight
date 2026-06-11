#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int s1 = a * b;
	int s2 = c * d;
	cout << (s1 > s2 ? s1 : s2) << endl;
	return 0;
}
