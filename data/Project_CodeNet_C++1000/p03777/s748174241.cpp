#include"bits/stdc++.h"
using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	char judge = 'D';
	if (a == b) {
		judge = 'H';
	}
	cout << judge << endl;
	return 0;
}