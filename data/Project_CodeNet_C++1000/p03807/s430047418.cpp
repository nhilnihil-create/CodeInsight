#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(int argc, char **argv)
{
	ll n; cin >> n;
	vector<ll> a(n); for (ll i = 0; i < n; ++i) cin >> a[i];
	ll odd_num{0};
	for (auto &e : a)
	{
		if (e & 1) ++odd_num;
	}
	std::cout << (odd_num & 1 ? "NO" : "YES" )<< std::endl;
}
