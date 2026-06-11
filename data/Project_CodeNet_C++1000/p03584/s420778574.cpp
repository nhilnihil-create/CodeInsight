#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll K;
pair<ll, ll> AB[100000 + 10];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> AB[i].first >> AB[i].second;

	int msb = 0;
	while (K >= (1 << msb))msb++;
	msb--;

	ll ans = 0;
	for (int i = 0; i < N; i++)if ((K | AB[i].first) == K)ans += AB[i].second;
	for (int i = msb; i >= 0; i--) {
		ll jougen = 0;
		//最初の(msb - i)桁はKと同じ。
		for (int j = i + 1; j <= msb; j++)jougen += ((K >> j) & 1) << j;
		//上からmsb - i + 1桁目は、0固定して、それより下の桁はすべて(1 << i) - 1になる。(2進数で全部1)
		if (!((K >> i) & 1))continue;
		jougen += 0;
		jougen += (1 << i) - 1;
		
		ll tmp = 0;
		for (int j = 0; j < N; j++)if ((jougen | AB[j].first) == jougen)tmp += AB[j].second;
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}