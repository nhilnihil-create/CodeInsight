#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 55;
const long double eps = 1e-6;
ll n, a, b;
ll v[N];
ll choose[N][N];

void init() {
	for(int i = 1; i < N; i++) {
		choose[i][0] = choose[i][i] = 1;
		for(int j = 1; j < i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	sort(v+1, v+n+1, greater<ll>());
	init();

	long double sum = 0;
	for(ll i = 1; i < a; i++)
		sum += 1.0*v[i];

	ll ans = 0;
	long double best = -1;
	for(ll i = a; i <= b; i++) {
		sum += 1.0*v[i];
		long double avr = sum / (1.0*i);
		if(avr < best) continue;
		if(avr > best)
			best = avr, ans = 0;

		ll cnt = 0, need = 0;
		for(int j = i+1; j <= n && abs(v[j] - v[i]) < eps; j++)
			cnt++;
		for(int j = i; j > 0 && abs(v[j] - v[i]) < eps; j--)
			cnt++, need++;
		ans += choose[cnt][need];
	}	

	cout << fixed << setprecision(6) << best << '\n';
	cout << ans << '\n';

	return 0;
}