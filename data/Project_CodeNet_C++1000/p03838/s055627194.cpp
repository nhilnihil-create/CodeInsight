#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll calc(ll x, ll y)
{
	if(x <= y) return y - x;
	return INF;
}
int main()
{
	ll x, y;
	cin >> x >> y;
	cout << min(min(calc(x, y), calc(-x, y) + 1), min(calc(x, -y) + 1, calc(-x, -y) + 2));
	return 0;
}
	 