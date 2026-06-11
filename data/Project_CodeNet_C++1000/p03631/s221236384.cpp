#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int n;

	cin >> n;
	if (n / 100 == n % 10)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}

