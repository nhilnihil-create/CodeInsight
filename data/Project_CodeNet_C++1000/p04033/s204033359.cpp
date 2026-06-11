#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string ans;
	if (b < 0) {
		if ((b - a) % 2 != 0) {
			ans = "Positive";
		}
		else {
			ans = "Negative";
		}
	}
	if (0 < a) {
		ans = "Positive";
	}
	if (a <= 0 && 0 <= b) {
		ans = "Zero";
	}
	cout << ans << endl;
	return 0;
}