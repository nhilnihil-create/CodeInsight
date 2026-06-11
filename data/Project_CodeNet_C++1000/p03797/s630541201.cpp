#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

int main()
{
	ll n, m;
	cin >> n >> m;
	ll res = 0;
	if (m / 2 <= n) cout << m / 2;
	else
	{
		m -= (n * 2);
		res += n + m / 4;
		cout << res;
	}
}