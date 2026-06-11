#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll K;
	cin >> K;
	int N = 50;
	ll X = (K + N - 1) / N;
	vector<ll> a(N, X + N - 1);
	ll cnt = X * N - K;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < N; j++) {
			if (j == i) {
				a[j] -= N;
			}
			else {
				a[j] += 1;
			}
		}
	}
	cout << N << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " \n"[i + 1 == N];
	}
	return 0;
}
