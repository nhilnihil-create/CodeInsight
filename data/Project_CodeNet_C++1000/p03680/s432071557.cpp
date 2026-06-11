#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)
	{
		cin >> a[i];
		a[i]--;
	}

	int ans = 0, tmp = 0;
	rep(i, n)
	{
		ans++;
		tmp = a[tmp];
		if (tmp == 1)
		{
			cout << ans << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
	return 0;
}
