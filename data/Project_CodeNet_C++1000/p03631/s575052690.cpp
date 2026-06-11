#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;
	string ans = "No";
	if (n.at(0) == n.at(2)) {
		ans = "Yes";
	}
	cout << ans << endl;
	return 0;
}