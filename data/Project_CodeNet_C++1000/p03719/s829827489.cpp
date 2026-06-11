#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	string ans;
	if (C >= A && C <= B) {
		ans = "Yes";
	}
	else {
		ans = "No";
	}
	cout << ans << endl;
}
