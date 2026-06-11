#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll h, w;
	cin >> h >> w;
	ll ans = 100000000000000000;
	if(h%3 == 0){
		ans = 0;
	}else{
		ans = w;
	}
	if(w%3 == 0){
		ans = 0;
	}else{
		ans = min(ans, h);
	}
	if(w%3 != 0){
		ll a0 = w/3;
		ll a1 = w/3+1;
		if(h%2 == 0){
			ll s0_0 = h*a0;
			ll s1_0 = (w-a0)*h/2;
			ll s2_0 = (w-a0)*(h-h/2);
			ll mi_0 = min(min(s0_0, s1_0), s2_0);
			ll ma_0 = max(max(s0_0, s1_0), s2_0);
			if(ans > ma_0 - mi_0) ans = ma_0 - mi_0;
			ll s0_1 = h*a1;
			ll s1_1 = (w-a1)*h/2;
			ll s2_1 = (w-a1)*(h-h/2);
			ll mi_1 = min(min(s0_1, s1_1), s2_1);
			ll ma_1 = max(max(s0_1, s1_1), s2_1);
			if(ans > ma_1 - mi_1) ans = ma_1 - mi_1;
		}else{
			ll b0 = h/2;
			ll b1 = h/2+1;
			ll s0_0 = h*a0;
			ll s1_0 = (w-a0)*b0;
			ll s2_0 = (w-a0)*(h-b0);
			ll mi_0 = min(min(s0_0, s1_0), s2_0);
			ll ma_0 = max(max(s0_0, s1_0), s2_0);
			if(ans > ma_0 - mi_0) ans = ma_0 - mi_0;
			ll s0_1 = h*a1;
			ll s1_1 = (w-a1)*b0;
			ll s2_1 = (w-a1)*(h-b0);
			ll mi_1 = min(min(s0_1, s1_1), s2_1);
			ll ma_1 = max(max(s0_1, s1_1), s2_1);
			if(ans > ma_1 - mi_1) ans = ma_1 - mi_1;
			ll s0_2 = h*a0;
			ll s1_2 = (w-a0)*b1;
			ll s2_2 = (w-a0)*(h-b1);
			ll mi_2 = min(min(s0_2, s1_2), s2_2);
			ll ma_2 = max(max(s0_2, s1_2), s2_2);
			if(ans > ma_2 - mi_2) ans = ma_2 - mi_2;
			ll s0_3 = h*a1;
			ll s1_3 = (w-a1)*b1;
			ll s2_3 = (w-a1)*(h-b1);
			ll mi_3 = min(min(s0_3, s1_3), s2_3);
			ll ma_3 = max(max(s0_3, s1_3), s2_3);
			if(ans > ma_3 - mi_3) ans = ma_3 - mi_3;
		}
	}
	swap(h, w);
	if(w%3 != 0){
		ll a0 = w/3;
		ll a1 = w/3+1;
		if(h%2 == 0){
			ll s0_0 = h*a0;
			ll s1_0 = (w-a0)*h/2;
			ll s2_0 = (w-a0)*(h-h/2);
			ll mi_0 = min(min(s0_0, s1_0), s2_0);
			ll ma_0 = max(max(s0_0, s1_0), s2_0);
			if(ans > ma_0 - mi_0) ans = ma_0 - mi_0;
			ll s0_1 = h*a1;
			ll s1_1 = (w-a1)*h/2;
			ll s2_1 = (w-a1)*(h-h/2);
			ll mi_1 = min(min(s0_1, s1_1), s2_1);
			ll ma_1 = max(max(s0_1, s1_1), s2_1);
			if(ans > ma_1 - mi_1) ans = ma_1 - mi_1;
		}else{
			ll b0 = h/2;
			ll b1 = h/2+1;
			ll s0_0 = h*a0;
			ll s1_0 = (w-a0)*b0;
			ll s2_0 = (w-a0)*(h-b0);
			ll mi_0 = min(min(s0_0, s1_0), s2_0);
			ll ma_0 = max(max(s0_0, s1_0), s2_0);
			if(ans > ma_0 - mi_0) ans = ma_0 - mi_0;
			ll s0_1 = h*a1;
			ll s1_1 = (w-a1)*b0;
			ll s2_1 = (w-a1)*(h-b0);
			ll mi_1 = min(min(s0_1, s1_1), s2_1);
			ll ma_1 = max(max(s0_1, s1_1), s2_1);
			if(ans > ma_1 - mi_1) ans = ma_1 - mi_1;
			ll s0_2 = h*a0;
			ll s1_2 = (w-a0)*b1;
			ll s2_2 = (w-a0)*(h-b1);
			ll mi_2 = min(min(s0_2, s1_2), s2_2);
			ll ma_2 = max(max(s0_2, s1_2), s2_2);
			if(ans > ma_2 - mi_2) ans = ma_2 - mi_2;
			ll s0_3 = h*a1;
			ll s1_3 = (w-a1)*b1;
			ll s2_3 = (w-a1)*(h-b1);
			ll mi_3 = min(min(s0_3, s1_3), s2_3);
			ll ma_3 = max(max(s0_3, s1_3), s2_3);
			if(ans > ma_3 - mi_3) ans = ma_3 - mi_3;
		}
	}
	cout << ans << endl;
	return 0;
}