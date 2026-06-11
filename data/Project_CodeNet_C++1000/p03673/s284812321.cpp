#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n;
	cin >> n;

	deque<int> B;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (n % 2 != i % 2)
			B.push_front(a);
		else
			B.push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		if (i)
			cout << " ";
		cout << B[i];
	}
	cout << endl;
}

