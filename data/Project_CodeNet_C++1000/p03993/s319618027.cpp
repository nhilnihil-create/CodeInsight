#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int		main(void)
{
	map<int, int> A;
	int N;

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int tmp;

		cin >> tmp;
		A[i] = tmp;
	}
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		int a = A[i];

		if (A[a] == i)
			cnt++;
	}
	cout << cnt / 2 << endl;
}

