#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define Y "Yes"
#define N "No"
#define ll long long
#define pi pair<int, int>
#define ppi pair<pi, pi>
using namespace std;

ll minl(ll a, ll b, ll c) {
	return min(min(a, b), c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll h, w, ma, mi1, mi2, ans = 1e10;
	cin >> h >> w;
	ll q = h, p = w;
	
	if (h % 3 < 2) ma = h/3;
	else ma = h/3 + 1;
	
	h -= ma;
	ma *= w;
	
	mi1 = h/2 * w;
	mi2 = w/2 * h;
	
	ll a[3];
	a[0] = ma;
	a[1] = mi1;
	a[2] = h*w - mi1;
	sort(a, a + 3);
	ans = min(ans, a[2] - a[0]);
	
	a[0] = ma;
	a[1] = mi2;
	a[2] = h*w - mi2;
	sort(a, a + 3);
	ans = min(ans, a[2] - a[0]);
	
	if (w % 3 < 2) ma = w/3;
	else ma = w/3 + 1;
	
	h = q;
	w = p;
	
	w -= ma;
	ma *= h;
	
	mi1 = h/2 * w;
	mi2 = w/2 * h;
	
	a[0] = ma;
	a[1] = mi1;
	a[2] = h*w - mi1;
	sort(a, a + 3);
	ans = min(ans, a[2] - a[0]);
	
	a[0] = ma;
	a[1] = mi2;
	a[2] = h*w - mi2;
	sort(a, a + 3);
	ans = min(ans, a[2] - a[0]);
	
	cout << ans;
}