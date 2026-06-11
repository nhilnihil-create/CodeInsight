#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string a, b; cin >> a >> b;
	if (b.size() < a.size()) {
		cout << "GREATER" << endl;
		return 0;
	}
	else if (a.size() < b.size()) {
		cout << "LESS" << endl;
		return 0;
	}
	int cnt = a.size();
	string ans = "EQUAL";
	while (cnt--) {
		int index = a.size() - (cnt + 1);
		int a_int = a[index] - '0';
		int b_int = b[index] - '0';
		if (a_int == b_int) {}
		else if (b_int < a_int) {
			ans = "GREATER";
			break;
		}
		else if (a_int < b_int) {
			ans = "LESS";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}