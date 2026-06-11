
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int H, W;
	cin >> H >> W;

	map<char, int> cnt;

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			char c;
			cin >> c;
			cnt[c]++;
		}
	}

	vector<int> num;
	for (auto itr : cnt) {
		num.push_back(itr.second);
	}

	vector<int> req;
	if (H % 2 == 1 && W % 2 == 1) {
		req.push_back(1);
	}

	for (int i=0; i<H/2; i++) {
		for (int j=0; j<W/2; j++) {
			req.push_back(4);
		}
	}

	if (H % 2 == 1) {
		for (int i=0; i<W/2; i++) {
			req.push_back(2);
		}
	}

	if (W % 2 == 1) {
		for (int i=0; i<H/2; i++) {
			req.push_back(2);
		}
	}

	/*
	// **** debug ****
	int q = 0;
	for (int k : req) {
		cout << k << " ";
		q += k;
	}
	cout << endl << q << endl;

	q = 0;
	for (int k : num) {
		cout << k << " ";
		q += k;
	}
	cout << endl << q << endl;
	*/

	string ans = "Yes";

	for (int r : req) {
		if (r == 1) {
			for (int i=0; i<num.size(); i++) {
				ans = "No";
				if (num[i] % 2 == 1) {
					num[i]--;
					ans = "Yes";
					break;
				}
			}
		} else if (r == 4) {
			for (int i=0; i<num.size(); i++) {
				ans = "No";
				if (num[i] >= 4) {
					num[i] -= 4;
					ans = "Yes";
					break;
				}
			}
		} else {
			for (int i=0; i<num.size(); i++) {
				ans = "No";
				if (num[i] >= 2) {
					num[i] -= 2;
					ans = "Yes";
					break;
				}
			}
		}

		if (ans == "No") break;
	}

	cout << ans << endl;

	return 0;
}