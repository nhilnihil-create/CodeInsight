#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int w,a,b;

	cin >> w >> a >> b;

	if((a<=b && b<=a+w) || (b<=a && a<=b+w))
	{
		cout << 0 << '\n';
	}
	else
	{
		if(a > b)
		{
			cout << abs(b+w - a) << '\n';
		}
		else
		{
			cout << abs(a+w - b) << '\n';
		}
	}
	return 0;
}
