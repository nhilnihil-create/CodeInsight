#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

ll solve(ll h,ll w){
    
	ll res = h * w;
	for(ll i = 1; i < h; i++){
		ll a = i * w;           //上
        ll b = (h-i) * w;       //下
		ll c = (i/2) * w;       //真ん中
		ll d = i * (w/2);       //width半分
		res = min(res, max({b, c, a-c}) - min({b, c, a-c})); //上中下
		res = min(res, max({b, d, a-d}) - min({b, d, a-d})); //左上、右上、下
	}
	return res;
}

int main(){

	ll h, w;
    cin >> h >> w;
	
    cout << min(solve(h,w), solve(w,h)) << endl;
	
    return 0;
}
