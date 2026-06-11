#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int n;

	cin >> n;
	if (n / 10 == 9 || n % 10 == 9)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}

