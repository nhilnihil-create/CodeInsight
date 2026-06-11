// ABC050A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int A, B;
	char op;
	cin >> A >> op >> B;

	if (op == '+') {
		cout << A + B << endl;
	} else {
		cout << A - B << endl;
	}

	return 0;
}
