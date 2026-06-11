#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;

int main() {
	string ans;
	cout << "? 1" << string(9, '0') << endl;
	cin >> ans;
	if (ans == "Y") {
		for (int i = 9; i > 0; i--) {
			cout << "? " << string(i, '9') << endl;
			cin >> ans;
			if (ans == "N") {
				cout << "! 1" << string(i, '0') << endl;
				return 0;
			}
		}
		cout << "! 1" << endl;
	}
	else {
		int d;
		for (d = 8; d > 0; d--) {
			cout << "? 1" << string(d, '0') << endl;
			cin >> ans;
			if (ans == "Y") break;
		}
		string now = "";
		for (int i = d; i >= 0; i--) {
			int l = 0, r = 10;
			while (r - l > 1) {
				int m = (l + r) / 2;
				cout << "? " << now << string(1, '0' + m) << string(9, '0') << endl;
				cin >> ans;
				if (ans == "Y") {
					cout << "? " << now << string(1, '0' + (m - 1)) << string(9, '9') << endl;
					cin >> ans;
					if (ans == "N") {
						cout << "! " << now << string(1, '0' + m) + string(i, '0') << endl;
						return 0;
					}
					r = m;
				}
				else l = m;
			}
			now += string(1, '0' + l);
		}
		cout << "! " << now << endl;
	}
}