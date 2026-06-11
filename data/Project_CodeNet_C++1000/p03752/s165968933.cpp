#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> r(n + 1);
	rep(i, n) {
		cin >> a[i];
		if (r[i] < a[i]) r[i + 1] = a[i];
		else r[i + 1] = r[i];
	}
	ll ans = 100000000000000;
	for (int bit = 0; bit < (1 << n); bit++) {
		ll ansi = 0;
		int cnt = 0;
		vector<int> v;
		rep(i, n) {
			if (bit & (1 << i)) {
				cnt++;
				v.push_back(i);
			}
		}
		if (cnt == k) {
          ll maxbuil=0;//高くしたやつ
			rep(i, k) {
				ansi += max((ll)0, max(r[v[i]],maxbuil) - a[v[i]]+1);
                maxbuil=a[v[i]]+max((ll)0, max(r[v[i]],maxbuil) - a[v[i]]+1);
			}
			ans = min(ans, ansi);
		}
	}
	cout << ans << endl;
}