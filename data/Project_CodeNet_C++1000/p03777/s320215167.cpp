#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int		main(void)
{
	char a, b;
	cin >> a >> b;
	char ans;
	if (a == 'H')
		b == 'H' ? ans = 'H' : ans = 'D';
	if (a == 'D')
		b == 'H' ? ans = 'D' : ans = 'H';
	cout << ans << endl;
}
