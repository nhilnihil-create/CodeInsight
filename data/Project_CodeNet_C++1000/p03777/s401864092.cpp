#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	char a,b;

	cin >> a >> b;

	if(a=='H')
	{
		cout << b << '\n';
	}
	else
	{
		if(b=='H')
		{
			cout << 'D' << '\n';
		}
		else
		{
			cout << 'H' << '\n';
		}
	}
	return 0;
}
