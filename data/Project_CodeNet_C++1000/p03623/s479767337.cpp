#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;




int main() {
	int x, a, b;
	cin >> x >> a >> b;
	a = abs(x - a);
	b = abs(x - b);
	if (a > b) cout << "B" << endl;
	else cout << "A" << endl;
	return 0;
}
