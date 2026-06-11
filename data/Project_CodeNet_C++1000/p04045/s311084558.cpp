#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	string ans = "failed";
	cin >> n >> k;
	vector<string> hate_num(k);
	for (int i = 0; i < k; i++) {
		cin >> hate_num.at(i);
	}

	while (true) {
		for (int i = 0; i < k; i++) {
			if (to_string(n).find(hate_num.at(i)) != string::npos) {
				break;
			}
			if (i >= k - 1) {
				ans = to_string(n);
			}
		}
		if (ans == "failed") {
			n++;
		} else {
			break;
		}
	}

	cout << ans << endl;
}