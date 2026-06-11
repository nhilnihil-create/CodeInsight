#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_N = 100050;
int n;
ll a[3*MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i,1,3*n+1) {
		cin >> a[i];
	}
	vl red;
	ll r = 0;
	priority_queue<ll> q;
	rep(i,1,n+1) {
		r += a[i];
		q.push(-a[i]);
	}
	red.pb(r);
	rep(k,n+1,2*n+1) {
		ll x = -q.top();
		r -= x;
		q.pop();
		ll y = a[k];
		if(y > x) {
			r += y;
			q.push(-y);
		} else {
			r += x;
			q.push(-x);
		}
		red.pb(r);
 	}
 	priority_queue<ll> qq;
 	vl blue;
 	ll b = 0;
 	rep(i,2*n+1, 3*n+1) {
 		b += a[i];
 		qq.push(a[i]);
 	}
 	blue.pb(b);
 	per(k,n+1,2*n+1) {
 		ll x = qq.top();
 		b -= x;
 		qq.pop();
 		ll y = a[k];
 		if(y > x) {
 			b += x;
 			qq.push(x);
 		} else {
 			b += y;
 			qq.push(y);
 		}
 		blue.pb(b);
 	}
 	reverse(all(blue));
 	ll ret = -1e18;
 	rep(i,0,sz(red)) {
 		ret = max(red[i] - blue[i], ret);
 	}
 	cout << ret << '\n';
	return 0;
}
