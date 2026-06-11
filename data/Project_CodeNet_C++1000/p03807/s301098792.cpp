#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N;
	int	cnt = 0;
	int	A;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A;
		if (A % 2 == 1)
			++cnt;
	}
	if (cnt % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

