#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int solve(vector<int> a)
{
	int odd = 0 , even = 0 , f = 0;

	for(auto x : a)
	{
		if(x % 2)
			odd++;
		else
			even++;

		if(x == 1)
			f = 1;
	}

	if(f)
		return even % 2;

	if(even == 0)
		return 0;
	
	if(odd == 1)
	{
		for(auto &x : a)
			if(x % 2 == 1)
				x--;
		int g = a[0];

		for(auto x : a)
			g = __gcd(g , x);

		for(auto &x : a)
			x /= g;

		return !solve(a);
	}

	return (even % 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> tmp;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		tmp.pb(x);
	}

	cout << (solve(tmp)? "First" : "Second") << endl;
}








