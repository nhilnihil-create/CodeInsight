#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli w, h, n;

int main(void){
	cin >> w >> h >> n;
	lli l, r, u, d;
	l = d = 0;
	r = w;
	u = h;
	rep(i, n){
		lli a, x, y;
		cin >> x >> y >> a;
		if(a == 1){
			l = max(l, x);
		}else if(a == 2){
			r = min(r, x);
		}else if(a == 3){
			d = max(d, y);
		}else{
			u = min(u, y);
		}
	}
	//cout << l << " " << r << " " << d << " " << u << endl;
	if(l > r || d > u) cout << 0 << endl;
	else cout << (r-l)*(u-d) << endl;
	return 0;
}
