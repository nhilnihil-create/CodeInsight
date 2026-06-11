#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;

double same(double x, double y) {
	return abs(x - y) < pow(10, -20);
}

ll nCk(ll n, ll k) {
	ll ans = 1;
	for (ll i = 0;i < k;i++) {
		ans *= (ll)n - i;
		ans /= i + 1;
	}
	return ans;
}

int main() {
	int N, A, B, cnt = 0, k = 0;
	cin >> N >> A >> B;
	vector<ll> X(N);
	ll V = 0, ans = 0, C = 0;
	for (int i = 0;i < N;i++)cin>>X[i];
	sort(all(X));
	reverse(all(X));
	for (int i = 0;i < A;i++) {
		V += X[i];
		if (X[i] == X[0])cnt++;
	}
	if (cnt >= A) {
		cnt = 0;
		for (int i = 0;i < N;i++)if (X[i] == X[0])cnt++;
		for (int i = min(cnt, B);i >= A;i--) {
			ans += nCk(cnt, i);
		}
	}
	else {
		cnt = 0;
		for (int i = 0;i < A;i++)
			if (X[i] == X[A - 1])cnt++;
		k = cnt;
		for (int i = A;i < N;i++)
			if (X[i] == X[A - 1])k++;
		ans = nCk(k, cnt);
	}
	printf("%.8f\n", (double)V / A);
	cout << ans << endl;
}