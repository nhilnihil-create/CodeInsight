#include "bits/stdc++.h"
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	char now = 'a';
	int index_a = 0, index_b = 0, index_c = 0;
	while (true)
	{
		if (now == 'a') {
			if (a.size() == index_a) {
				cout << 'A' << endl;
				break;
			}
			now = a.at(index_a++);
		}
		else if (now == 'b') {
			if (b.size() == index_b) {
				cout << 'B' << endl;
				break;
			}
			now = b.at(index_b++);
		}
		else {
			if (c.size() == index_c) {
				cout << 'C' << endl;
				break;
			}
			now = c.at(index_c++);
		}
	}

	return 0;
}