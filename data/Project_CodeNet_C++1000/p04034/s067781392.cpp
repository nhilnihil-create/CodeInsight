#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	vector<pair<ll, ll>> to(M);
	vector<ll> box(N, 1);
	vector<bool> come_red(N, false);
	come_red[0] = true;
	
	for (ll i = 0; i < M; ++i)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		to[i] = pair<ll, ll>(a, b);

		--box[a], ++box[b];
		if (come_red[a])
			come_red[b] = true;
		if (box[a] == 0)
			come_red[a] = false;
	}
	
	ll res{0};
	for (ll i = 0; i < N; ++i)
	{
		if (come_red[i] && box[i])
			++res;
		
	}
	
	std::cout << res << std::endl;
}
