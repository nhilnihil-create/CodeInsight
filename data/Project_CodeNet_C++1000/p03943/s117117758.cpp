// ABC047A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	sort(a, a + 3);

	if (a[0] + a[1] == a[2]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
