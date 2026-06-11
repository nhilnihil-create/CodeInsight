#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 0x3f3f3f3f;
ll H, W;

void solve()
{
	if(H%3==0 || W%3==0) cout << 0 << '\n';
	else{
		ll ans = 1e18;
		for(int w=1;w<W;++w){
			ll a1 = w*H, a2 = (W-w)*(H/2), a3 = H*W-a1-a2;
			ll mx = max(a1,max(a2,a3));
			ll mi = min(a1,min(a2,a3));
			ans=min(ans, mx-mi);
			a2 = H*((W-w)/2), a3 = H*W-a1-a2;
			mx = max(a1,max(a2,a3));
			mi = min(a1,min(a2,a3));
			ans = min(ans, mx-mi);
		}
		swap(H,W);
		for(int w=1;w<W;++w){
			ll a1 = w*H, a2 = (W-w)*(H/2), a3 = H*W-a1-a2;
			ll mx = max(a1,max(a2,a3));
			ll mi = min(a1,min(a2,a3));
			ans=min(ans, mx-mi);
			a2 = H*((W-w)/2), a3 = H*W-a1-a2;
			mx = max(a1,max(a2,a3));
			mi = min(a1,min(a2,a3));
			ans = min(ans, mx-mi);
		}
		cout << ans << '\n';
	}
}

int main()
{
	cin >> H >> W;
	solve();
	return 0;
}