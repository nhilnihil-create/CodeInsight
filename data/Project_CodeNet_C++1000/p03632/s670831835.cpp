#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>

using namespace std;



int main() {
	pair<int, int> x;
	pair<int, int> y;
	cin >> x.first >> x.second >> y.first >> y.second;

	int a = max(x.first, y.first);
	int b = min(x.second, y.second);

	if (b - a < 0) {
		cout << 0 << endl;
	}
	else {
		cout << b - a << endl;
	}

	return 0;
}