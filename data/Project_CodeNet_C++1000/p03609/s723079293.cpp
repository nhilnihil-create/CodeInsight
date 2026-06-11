#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;




int main() {
	int x, t;
	cin >> x >> t;
	if (x >= t) cout << x - t << endl;
	else cout << "0" << endl;

	return 0;
}
