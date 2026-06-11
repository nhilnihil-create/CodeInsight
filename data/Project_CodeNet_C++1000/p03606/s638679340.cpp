#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	ll res{0};
	for (ll i = 0; i < N; ++i)
	{
		ll a, b; cin >> a >> b;
		res += b - a + 1;
	}
	std::cout << res << std::endl;
}