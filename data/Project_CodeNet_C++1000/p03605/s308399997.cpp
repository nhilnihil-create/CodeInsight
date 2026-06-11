#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	char a, b;
	cin >> a >> b;
	int count = 0;
	if (a == '9') {
		count++;
	}
	if (b == '9') {
		count++;
	}
	if (count > 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}