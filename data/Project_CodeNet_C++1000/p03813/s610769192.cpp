#include <iostream>
#include <string>
using namespace std;

int main() {
	int x;
	cin >> x;
	string ans;
	if (1200 <= x) {
		ans = "ARC";
	} else {
		ans = "ABC";
	}
	cout << ans << endl;
	return 0;
}