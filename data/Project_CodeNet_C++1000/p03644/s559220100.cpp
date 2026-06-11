#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[4][4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	ll ct = 1;
	while (ct <= n)
		ct = ct * 2;
	cout << ct / 2;
	return 0;
}
