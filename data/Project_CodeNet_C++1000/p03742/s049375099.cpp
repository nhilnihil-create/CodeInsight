#include<bits/stdc++.h>
#include<cmath>
#define ll long long
using namespace std;
signed main()
{
	
	
		ll x, y;
	cin >> x >> y;
	if (abs(x - y) <= 1)
	{
		cout << "Brown\n";
	}
	else
	{
		cout << "Alice\n";
	}
	
	return 0;
}