#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int		main(void)
{
	int a, b;
	cin >> a >> b;

	int ans = a + b;
	if (ans > 24)
		ans -= 24;
	if (ans == 24)
		ans = 0;
	cout << ans << endl;
}

