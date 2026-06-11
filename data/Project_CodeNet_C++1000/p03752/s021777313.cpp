#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 1LL << 60;
	for(int bit = 1; bit < (1 << n); bit++) {
		// bitが1の建物が見えるようにする（0の建物は高さを増やさないが、見えても良い）
		int cnt = 0;
		rep(i, n) {
			if(bit & 1 << i) cnt++;
		}
		if(cnt < k) continue;	// 見える建物がk未満の組み合わせは飛ばす
		vector<ll> b = a;
		ll sum = 0;
		rep(i, n) {
			if(!(bit & 1 << i)) continue;
			// bitが1の建物について
			ll high = 0;	// high: i未満の建物の中で最大の高さ
			rep(j, i) {
				high = max(high, b[j]);
			}
			// i番目の建物が見えるように、b[i] <= highならhigh+1-b[i]だけ高さを増やす。
			if(b[i] <= high){
				sum += high + 1 - b[i];
				b[i] = high + 1;
			}
		}
		ans = min(ans, sum);
	}
	
	cout << ans << endl;
	return 0;
}