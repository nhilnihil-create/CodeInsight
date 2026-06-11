#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main()
{
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	vector<int> v(N);
	for (int i = 1; i < N; i++) {
		v[i] = v[i - 1] + (x[i - 1] >= (i - v[i - 1]) * 2 - 1 ? 0 : 1);
	}
	ll res = 1;
	for (int i = 0; i < N; i++) {
		res = (res * (i + 1 - v[i])) % mod;
	}
	cout << res << endl;
	return 0;
}
