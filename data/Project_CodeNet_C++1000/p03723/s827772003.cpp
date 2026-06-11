#include <bits/stdc++.h>

using namespace std;

int main() {

	long long a, b, c;
	cin >> a >> b >> c;
	long long tmpa, tmpb,tmpc;
	int counter = 0;
	while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
		counter++;
		tmpa = a;
		tmpb = b;
		tmpc = c;
		a = tmpb / 2 + tmpc / 2;
		b = tmpa / 2 + tmpc / 2;
		c = tmpa / 2 + tmpb / 2;
		if (counter > 1000){
			cout << -1 << endl;
				return 0;
		}
	}

	cout << counter << endl;
	return 0;
}