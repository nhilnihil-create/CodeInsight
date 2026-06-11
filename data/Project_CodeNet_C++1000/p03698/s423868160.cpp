#include <iostream>
#include <string>
using namespace std;
int main() {
	bool d[128] = { false };
	bool flag = true;
	string s;
	cin >> s;
	for (auto i : s) {
		if (!d[i]) {
			d[i] = true;
		}
		else {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}