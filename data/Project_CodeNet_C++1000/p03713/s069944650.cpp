// C - Chocolate Bar
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll min_Diff(ll minDiff, ll s1, ll s2, ll s3){
	return min(minDiff, max({s1, s2, s3}) - min({s1, s2, s3}));
}

ll check(int Y, int X){
	ll minDiff = LLONG_MAX;
	ll e = (Y+2-1)/2;//roundup
	for(ll y1=1; y1<=e; ++y1){//-: vertical division
		ll y2,y3,x2,x3;
		// T: horizontal division
		y2 = Y - y1;
		x2 = X / 2;
		x3 = X - x2;
		minDiff = min_Diff(minDiff, y1*X, y2*x2, y2*x3);
		//-: vertical division
		y2 = y2 / 2;
		y3 = Y - y1 - y2;
		minDiff = min_Diff(minDiff, y1*X, y2*X, y3*X);
	}
	return minDiff;
}

int main(){
	int H,W; cin>>H>>W;
	ll ans = min(check(H, W), check(W, H));
	cout<< ans <<endl;
}