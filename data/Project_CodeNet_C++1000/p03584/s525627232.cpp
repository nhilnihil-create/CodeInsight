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

const int K = 31;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll> > v(n);
	rep(i,0,n) {
		cin >> v[i].F >> v[i].S;
	}
	ll L = 0;
	ll ret = 0;
	rep(i,0,n) {
		if(v[i].F == 0) ret += v[i].S;
	}
	per(i,0,K) {
		if((k & (1LL << i)) == 0) continue;
		ll l = (L | ((1LL << i) - 1));
		ll loc = 0;
		rep(i,0,n) {
			if((v[i].F & l) == v[i].F) {
				loc += v[i].S;
			}
		}
		ret = max(ret, loc);
		l = (L | (1LL << i));
		loc = 0;
		rep(i,0,n) {
			if((v[i].F & l) == v[i].F) {
				loc += v[i].S;
			}
		}
		ret = max(ret, loc);
		L = (L | (1LL << i));
	}
	cout << ret << '\n';
	return 0;
}
