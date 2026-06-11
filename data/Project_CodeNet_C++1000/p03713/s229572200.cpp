#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

ll t(ll h, ll w){
	ll ans = LINF;
	for(ll i = 1; i < h; i++) {
		ll a = i*w;
		ll b = (h - i)*(w/2);
		ll c = (h - i)*(w - w/2);
		ll smax = max(a,max(b,c));
		ll smin = min(a,min(b,c));
		ans = min(ans,smax - smin);
	}
	return ans;
}
ll to(ll h, ll w){
	ll ans = LINF;
	for(ll i = 1; i < w; i++) {
		ll a = i*h;
		ll b = (w - i)*(h/2);
		ll c = (w - i)*(h - h/2);
		ll smax = max(a,max(b,c));
		ll smin = min(a,min(b,c));
		ans = min(ans,smax - smin);
	}
	return ans;
}

ll ni(ll h,ll w){
	ll ans = LINF;
	for(ll i = 1; i < h; i++) {
		ll a = i*w;
		ll b = ((h - i)/2)*w;
		ll c = (h- i - (h - i)/2)*w;
		ll smax = max(a,max(b,c));
		ll smin = min(a,min(b,c));
		ans = min(ans,smax - smin);
	}
	return ans;
}

ll H(ll h,ll w){
	ll ans = LINF;
	for(ll i = 1; i < w; i++) {
		ll a = i*h;
		ll b = (w - i)/2*h;
		ll c = (w- i - (w - i)/2)*h;
		ll smax = max(a,max(b,c));
		ll smin = min(a,min(b,c));

		ans = min(ans,smax - smin);
	}
	return ans;
}





int main(){
	ll h,w;
	cin >> h >> w;
	ll ans = LINF;
	if (h > 2){
		ans = min(ans,ni(h,w));
		// cout << "ni" << ni(h,w) << endl;
	}
	if (w > 2){
		ans = min(ans,H(h,w));
		// cout << "H" << H(h,w) << endl;
	}
	ans = min(ans,t(h,w));
	// cout << "t" << t(h,w) << endl;
	ans = min(ans,to(h,w));
	// cout << "to" << to(h,w) << endl;
	cout << ans << endl;
	return 0;
}