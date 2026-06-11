#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1000000007LL;
int main() {
	cout << "? 1000000000" << endl;
	string ans;
	cin >> ans;
	if (ans == "Y") {
		for (int i = 8; i >= 1; i--) {
			cout << "? 1" + string(i - 1, '0') + "1" << endl;
			cin >> ans;
			if (ans == "N") {
				cout << "! 1" + string(i + 1, '0') << endl;
				return 0;
			}
		}
		cout << "? 9" << endl;
		cin >> ans;
		if (ans == "Y") cout << "! 1" << endl;
		else cout << "! 10" << endl;
	}
	else {
		int l = 1, r = 10;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			cout << "? 1" + string(m - 1, '0') << endl;
			cin >> ans;
			if (ans == "Y") {
				l = m;
			}
			else {
				r = m;
			}
		}
		int d = l;
		vector<int> vec;
		for (int i = 0; i < d; i++) {
			l = 0, r = 10;
			if (i == 0) l = 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				cout << "? ";
				for (int j = 0; j < i; j++) cout << vec[j];
				cout << m;
				for (int j = 0; j < d - i; j++) cout << 0;
				cout << endl;
				cin >> ans;
				if (ans == "Y") {
					cout << "? ";
					for (int j = 0; j < i; j++) cout << vec[j];
					cout << m - 1;
					for (int j = 0; j < d - i; j++) cout << 9;
					cout << endl;
					cin >> ans;
					if (ans == "Y") {
						r = m;
					}
					else {
						cout << "! ";
						for (int j = 0; j < i; j++) cout << vec[j];
						cout << m;
						for (int j = 0; j < d - i - 1; j++) cout << 0;
						cout << endl;
						return 0;
					}
				}
				else {
					l = m;
				}
			}
			vec.push_back(l);
		}
		cout << "!";
		for (int i = 0; i < vec.size(); i++) cout << " " << vec[i];
		cout << endl;
	}
}