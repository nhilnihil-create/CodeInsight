#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int	X, A, B;	cin >> X >> A >> B;
	if (A < B)
		cout << (X < B - A ? "dangerous" : "safe") << endl;
	else
		cout << "delicious" << endl;
}