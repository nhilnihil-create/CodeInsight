#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	string poof[n];
	for (int i = 0; i < n; i++) {
		cin >> poof[i];
	}
	sort(poof, poof+n);
	for (string s: poof) {
		cout << s;
	}
	cout << endl;
	return 0;
}