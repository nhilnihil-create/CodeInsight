#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main()
{
	ll x;
	cin >> x;
	ll a, b;

	if (x % 11 == 0) a = (x / 11) * 2;
	else a = (x / 11 + 1) * 2;
	if ((x + 5) % 11 == 0) b = ((x + 5) / 11) * 2 - 1;
	else b = ((x + 5) / 11 + 1) * 2 - 1;
	cout << min(a, b) << endl;
}