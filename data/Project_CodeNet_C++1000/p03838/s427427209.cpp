#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll a, b; cin >> a >> b;

	ll res{INF};
	if (a <= b) res = min(res, b - a);
	if (-a <= b) res = min(res, b + a + 1);
	if (-a >= b) res = min(res, -a - b + 1);
	if (b <= a) res = min(res, 2 + a - b);
	std::cout << res << std::endl;
}