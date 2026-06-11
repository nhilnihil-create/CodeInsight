#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	string str; cin >> str;

	ll res{0};
	for (ll i = 0; i+1 < (ll)str.size(); ++i)
		res += (str[i] != str[i+1]);
	std::cout << res << std::endl;
}
