// ABC066A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);

	cout << a[0] + a[1] << endl;

	return 0;
}
