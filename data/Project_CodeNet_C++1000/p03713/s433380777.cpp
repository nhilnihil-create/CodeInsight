// C - Chocolate Bar
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,n) for(int i=0;i<(n);++i)

ll check(int Y, int X){
	ll s1,s2,s3;
	ll minDiff = LLONG_MAX;
	ll e = (Y+2-1)/2;
	for(ll x1=X, y1=1; y1<=e; ++y1){//-: vertical division
		ll y2,y3,x2,x3;
		// T: horizontal division
		y2 = Y-y1;
		x2 = X/2;
		x3 = X-x2;

		s1 = y1 * x1;
		s2 = y2 * x2;
		s3 = y2 * x3;
		ll diff = max({s1, s2, s3}) - min({s1, s2, s3});
		minDiff = min(minDiff, diff);

		//-: vertical division
		y2 = y2/2;
		y3 = Y - y1 - y2;

		s1 = y1 * x1;
		s2 = y2 * x1;
		s3 = y3 * x1;
		diff = max({s1, s2, s3}) - min({s1, s2, s3});
		minDiff = min(minDiff, diff);

	}
	return minDiff;
}

int main(){
	int H,W; cin>>H>>W;
	ll ans = min(check(H, W), check(W, H));
	cout<< ans <<endl;
}