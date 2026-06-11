#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	else return GCD(b, a%b);
}

ll n, k;
vector<long long> a;

int main(int argc, char **argv)
{
	a.resize(10000000);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	ll g{0};
	ll max{0};
	for (int i = 0; i < n; ++i)
	{
		g = GCD(g, a[i]);
	}
	max = *max_element(a.begin(), a.end());

	string ans;
	if (max >= k && k % g == 0)
		ans = "POSSIBLE";
	else
		ans = "IMPOSSIBLE";

	std::cout << ans << std::endl;
	
}
