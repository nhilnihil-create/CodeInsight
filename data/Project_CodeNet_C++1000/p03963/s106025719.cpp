#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"


int pow(int a, int b)
{
	int ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans * a);
		b /= 2;
		a = (a * a);
	}
	return ans;
}

int32_t main()
{
	IOS;
	int n, k;
	cin >> n >> k;
	if (n == 1)
		cout << k << endl;
	else if (n == 2)
	{
		cout << k*(k - 1) << endl;
	}
	else
	{
		cout << k*pow(k - 1, n - 1) << endl;
	}


	return 0;
}