#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int W, H, N;
	cin >> W >> H >> N;
	int l=0, r=W, d=0, u=H;
	rep(i,N) {
		int x, y, a;
		cin >> x >> y >> a;
		switch (a) {
			case 1:
				if (x > l) l = x;
				break;
			case 2:
				if (x < r) r = x;
				break;
			case 3:
				if (y > d) d = y;
				break;
			case 4:
				if (y < u) u = y;
				break;
		}
	}

	int ans = (r-l)*(u-d);
	if (r < l || u < d) ans = 0;
	cout << ans << endl;

	return 0;
}
