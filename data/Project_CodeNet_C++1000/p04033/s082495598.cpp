#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	if (a > 0)
		cout << "Positive" << endl;
	else if (a == 0 || b == 0 || (a < 0 && b > 0)) {
		cout << "Zero" << endl;
	}
	else {
		ll tmp = abs(b) - abs(a);
		if (tmp & 1) {
			cout << "Positive" << endl;
		}
		else {
			cout << "Negative" << endl;
		}
	}
	return 0;
}