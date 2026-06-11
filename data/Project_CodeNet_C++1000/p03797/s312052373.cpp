#include <bits/stdc++.h>
using namespace std;

int		main()
{
	long long N, M; cin >> N >> M;
	if (N * 2 == M) cout << N;
	else if (N * 2 > M)
	{
		cout << M / 2;
	}
	else
	{
		cout << N + (M - 2 * N) / 4;
	}
	cout << endl;
}

