#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int mod = 1e9 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, M;
	cin >> N >> M;
	ll factN = 1, factM = 1;
	for (ll i = 1; i <= N; i++)
		factN = factN * i % mod;
	for (ll i = 1; i <= M; i++)
		factM = factM * i % mod;
	if (N + 1 == M || M + 1 == N)
		cout << (ll) factN * factM % mod << endl;
	else if (N == M)
		cout << (ll) 2 * factM * factN % mod;
	else
		cout << 0 << endl;

}

