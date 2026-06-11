#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

ll X, Y;

bool slove() {
	if (abs(X - Y) <= 1) {
		return false;
	}
	return true;
}

int main() {
	cin >> X >> Y;
	if (slove()) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Brown" << endl;
	}
	return 0;
}