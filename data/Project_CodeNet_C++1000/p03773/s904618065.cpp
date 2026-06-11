#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int		A, B;

	cin >> A >> B;
	for (int i = 0; i < B; B--)
	{
		A++;
		if (A == 24)
			A = 0;
	}
	cout << A << endl;
}