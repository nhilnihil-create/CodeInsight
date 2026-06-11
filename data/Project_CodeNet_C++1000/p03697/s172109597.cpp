#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;

	if (10 <= a + b) {
		cout << "error" << endl;
		return 0;
	}

	cout << a + b << endl;

	return 0;
}