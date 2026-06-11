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

	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	sort(all(A));
	int ans = 0;
	int tmp = A[0];
	int cnt = 1;
	for (int i = 1; i < n; ++i)
	{
		if (A[i] == tmp)
			++cnt;
		else
		{
			if (cnt % 2 == 1)
				++ans;
			tmp = A[i];
			cnt = 1;
		}
	}
	if (cnt % 2 == 1)
		++ans;
	cout << ans << endl;
}

