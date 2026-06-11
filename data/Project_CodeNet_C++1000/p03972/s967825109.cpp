#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	ll w, h;
	vector<pair<ll, ll> > e;
	cin >> w >> h;
	rep(i,0,w) {
		ll a;
		cin >> a;
		e.pb(mp(a,0));
	}
	rep(i,0,h) {
		ll a;
		cin >> a;
		e.pb(mp(a,1));
	}
	sort(all(e));
	h++;
	w++;
	ll cost = 0;
	rep(i,0,sz(e)) {
		ll d;
		if(e[i].S == 0) {
			d = h;
		} else {
			d = w;
		}
		cost += e[i].F * d;
		if(e[i].S == 0) {
			w--;
		} else {
			h--;
		}
	}
	cout << cost << '\n';
	return 0;
}
