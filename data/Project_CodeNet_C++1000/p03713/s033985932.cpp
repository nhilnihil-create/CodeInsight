// C - Chocolate Bar
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rp(i,n) for(int i=0;i<(n);++i)

ll check1(int Y, int X){//"||||"
	ll s1,s2,s3;
	ll minDiff = LLONG_MAX;
	ll e = (X+3-1)/3;
	for(ll x1=1; x1<=e; ++x1){
		ll x2 = (X-x1)/2;
		ll x3 = X - x1 - (X-x1)/2;
		s1 = Y * x1;
		s2 = Y * x2;
		s3 = Y * x3;
		ll diff = max({s1, s2, s3}) - min({s1, s2, s3});
		minDiff = min(minDiff, diff);
	}
	return minDiff;
}

ll check2(int Y, int X){//"T"
	ll s1,s2,s3;
	ll minDiff = LLONG_MAX;
	ll e = (Y+2-1)/2;
	for(ll y1=1; y1<=e; ++y1){
		ll y2 = Y-y1;
		ll x1 = X;
		ll x2 = X/2;
		ll x3 = X-x2;
		s1 = y1 * x1;
		s2 = y2 * x2;
		s3 = y2 * x3;
		ll diff = max({s1, s2, s3}) - min({s1, s2, s3});
		minDiff = min(minDiff, diff);
	}
	return minDiff;
}

int main(){
	int H,W; cin>>H>>W;
	ll ans = LLONG_MAX;
	ans = min({ans, check1(H, W), check1(W, H)});
	ans = min({ans, check2(H, W), check2(W, H)});
	cout<< ans <<endl;
}