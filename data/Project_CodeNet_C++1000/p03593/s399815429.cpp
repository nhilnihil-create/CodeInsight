#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w; cin >> h >> w;
	map<char, int>ct;
	for (int i = 0; i < h * w; i++) {
		char x;
		cin >> x;
		if (ct.count(x))ct.at(x)++;
		else ct[x] = 1;
	}
	ll m4 = 0; ll m2 = 0; ll m1 = 0;
	for (auto a : ct) {
		int x = a.second;
		m4 += x / 4;
		x -= (x / 4) * 4;
		m2 += x / 2;
		x -= (x / 2) * 2;
		m1 += x;
	}
	if (h % 2 == 1 && w % 2 == 1) {
		if (m4 >= ((h - 1) / 2) * ((w - 1) / 2)) {
			m2 += (m4 - ((h - 1) / 2) * ((w - 1) / 2)) * 2;
			if (m2 >= (h - 1) / 2 + (w - 1) / 2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	else if (h % 2 == 0 && w % 2 == 0) {
		if (m4 >= (h / 2) * (w / 2))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		if (h % 2 == 1)swap(h, w);
		if (m4 >= (w - 1) * h / 4) {
			m2 += (m4 - (w - 1) * h / 4) * 2;
			if (m2 >= h / 2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
}