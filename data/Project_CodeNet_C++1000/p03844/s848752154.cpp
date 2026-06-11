#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, ans;
	string x;
	cin >> A >> x >> B;

	if (x == "+") {
		ans = A + B;
	}
	else if (x == "-") {
		ans = A - B;
	}
	cout << ans;
}