#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
using namespace std;
#define rep(i,l,r) for(int i=l;i<r;i++)
#define repb(i,r,l) for(int i=r;i>l;i--)
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

void solve() {
	ll h, w;
	cin >> h >> w;
	if(h > w) swap(h, w);
 
	ll ans = (w % 3 > 0) * h;
	ans = min(ans, (h % 3 > 0) * w);
	for(ll i = 1; i < w; ++i) {
		ll mx = max(i * h, (w - i) * ((h + 1) / 2));
		ll mn = min(i * h, (w - i) * (h / 2));
		ans = min(ans, mx - mn);
	}
	for(ll i = 1; i < h; ++i) {
		ll mx = max(i * w, (h - i) * ((w + 1) / 2));
		ll mn = min(i * w, (h - i) * (w / 2));
		ans = min(ans, mx - mn);
	}
	cout << ans;
}

int main() {
    solve();
    return 0;
}