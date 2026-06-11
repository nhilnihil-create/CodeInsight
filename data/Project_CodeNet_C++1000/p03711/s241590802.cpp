// ABC062A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int a[13] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
	int x, y;
	cin >> x >> y;

	if (a[x] == a[y]) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
