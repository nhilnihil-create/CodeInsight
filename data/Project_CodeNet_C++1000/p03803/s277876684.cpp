#include <bits/stdc++.h>
using namespace std;

int a, b; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
	cin >> a >> b;

	if (a == 1) {
		a = 14;
	}

	if (b == 1) {
		b = 14;
	}

	if (a > b) {
		cout << "Alice\n";
	}
	else if (b > a) {
		cout << "Bob\n";
	}
	else {
		cout << "Draw\n";
	}
 
	return 0;
}