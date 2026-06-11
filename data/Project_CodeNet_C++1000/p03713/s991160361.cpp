#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int h, w;
int main() {
	cin>>h>>w;
	ll ans = (ll)h*(ll)w;
	if (h >= 3) {
		if (h%3 == 0) ans = min(ans, 0LL);
		else {
			ans = min(ans, (ll)w);
		}
	}
	if (w >= 3) {
		if (w%3 == 0) ans = min(ans, 0LL);
		else {
			ans = min(ans, (ll)h);
		}
	}
	for (int j = 1; j < w; ++j) {
		vector<ll> xs;
		xs.clear();
		xs.push_back((ll)j * (ll)h);
		if (h % 2 == 0) {
			xs.push_back((ll)(w-j) * (ll)h / 2);
		} else {
			xs.push_back((ll)(w-j) * (ll)(h / 2));
			xs.push_back((ll)(w-j) * (ll)((h+1)/2));
		}
		sort(xs.begin(), xs.end());
		ans =min(ans, (ll)(xs.back()-xs[0]));
	//	cout<<j<<" "<<ans<<endl;
	}
	for (int i = 1; i < h; ++i) {
		vector<ll> xs;
		xs.clear();
		xs.push_back((ll)i * (ll)w);
		if (w % 2 == 0) {
			xs.push_back((ll)(h-i) * (ll)w / 2);
		} else {
			xs.push_back((ll)(h-i) * (ll)(w / 2));
			xs.push_back((ll)(h-i) * (ll)((w+1)/2));
		}
		sort(xs.begin(), xs.end());
		ans = min(ans, (ll)(xs.back()-xs[0]));
	//	cout<<i<<" "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}