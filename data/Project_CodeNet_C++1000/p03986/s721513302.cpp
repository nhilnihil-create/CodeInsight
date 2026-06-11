#include <bits/stdc++.h>
using namespace std;

int main() {
	string x;
	cin >> x;
	int pre_t = 0;
	int post_s = 0;
	for (int i = 0; i < x.length(); i++) {
		char a;
		a = x.at(i);
		if (post_s == 0) {
			if (a == 'S') post_s++;
			else pre_t++;
		}
		else if (post_s >= 1) {
			if (a == 'S')post_s++;
			else post_s--;
		}
	}
	cout << pre_t + post_s << endl;
}
