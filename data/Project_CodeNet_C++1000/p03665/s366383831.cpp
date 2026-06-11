#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N, P;
	cin >> N >> P;

	bool even = true;
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		if (A % 2 == 1)
			even = false;
	}
	if (even)
	{
		if (P == 0)
			cout << (ll)pow(2, N) << endl;
		else
			cout << 0 << endl;
	}
	else
	{
		cout << (ll)pow(2, N-1) << endl;
	}
}

