#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int a,b;

	cin >> a >> b;

	if(a<=0 && b>=0)
	{
		cout << "Zero" << '\n';
	}
	else if(b<0)
	{
		long long int d = abs(a-b) + 1;
		if(d%2==1)
		{
			cout << "Negative" << '\n';
		}
		else
		{
			cout << "Positive" << '\n';
		}
	}
	else
	{
		cout << "Positive" << '\n';
	}
	return 0;
}