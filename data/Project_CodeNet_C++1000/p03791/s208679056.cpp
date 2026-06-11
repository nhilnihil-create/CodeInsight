#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll N;
ll x[100000 + 100];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> x[i];

	ll ans = 1, cnt = 1;
	ll used = 0;
	for (int i = 1; i < N; i++) {
		ll need;
		need = (i - 1) * 2 + 1;
		if (x[i - 1] + used * 2 - need < 0) {
			//左へ行けるリストのうち、1つを必ずリリースしないと今の場所より向こうは、ゴールできない
			ans *= cnt;
			used++;
		}
		else {
			cnt++;
		}
		ans %= MOD;
	}
	for (ll i = 1; i <= cnt; i++) {
		ans *= i;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}