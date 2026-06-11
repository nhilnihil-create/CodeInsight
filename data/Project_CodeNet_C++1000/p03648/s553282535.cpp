#include <bits/stdc++.h>
using namespace std;

constexpr int INF       = 1000000000;/* 1e+9a */
constexpr int MODULO    = 1000000007;

typedef int64_t ll;

int main()
{
	cin.tie(0);
    ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll k = n / 50;
	vector<ll> ou(50);
	for (int i = 0; i < 50; i++) {
		ou[i] = i+k;
	}
	k = n % 50;
	for (int i = 0; i < k; i++) {
		ou[i] += 50;
		for (int j = 1; j < 50; j++) {
			ou[(i+j)%50] -= 1;
		}
	}

	cout << "50\n";
	for (auto&& t : ou) {
		cout << t << ' ';
	}
	cout << endl;

}

