#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const int INF=1e9+7;

int main() {
	ll H,W,r=INF,t,c1,c2,c3;
	cin >> H >> W;

	rep(i,2) {
		rep(j,H) {
			t = j+1;

			c1 = t*W;
			c2 = (H-t)*(W/2);
			c3 = H*W-c1-c2;
			r = min(r, max(c1,max(c2,c3))-min(c1,min(c2,c3)));

			c2 = ((H-t)/2)*W;
			c3 = H*W-c1-c2;
			r = min(r, max(c1,max(c2,c3))-min(c1,min(c2,c3)));
		}
		swap(H,W);
	}

	cout << r << endl;
}