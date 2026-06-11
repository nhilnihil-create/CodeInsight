#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int x, a, b;
	cin >> x >> a >> b;
	int xa, xb;
	xa = abs(x - a);
	xb = abs(x - b);
	if (xa <= xb) cout << "A" << endl;
	else cout << "B" << endl;
	return 0;
}