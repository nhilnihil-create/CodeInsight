#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mod 1000000007
// #define mod 998244353
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if (a <= 0 && b >= 0)
	{
		cout << "Zero" << endl;
		return 0;
	}
	if (a > 0)
	{
		cout << "Positive" << endl;
		return 0;
	}
	cout << ((b - a) % 2 ? "Positive" : "Negative") << endl;
	return 0;
}