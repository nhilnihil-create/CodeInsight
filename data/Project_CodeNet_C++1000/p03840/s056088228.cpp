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

const int N = 7;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("in.txt", "r", stdin);
	vl a(N);
	rep(i,0,sz(a)) {
		cin >> a[i];
	}
	ll ret = a[1];
	ll x = min(a[0], min(a[3],a[4]));
	ll y = a[0]%2 + a[3]%2 + a[4]%2;
	if(y >= 2) {
		x = min(1LL, x);
	} else {
		x = 0;
	}
	rep(i,0,x+1) {
		ll loc = a[1] + 3 * i;
		loc += ((a[0]-i)/2)*2;
		loc += ((a[3]-i)/2)*2;
		loc += ((a[4]-i)/2)*2;
		ret = max(ret, loc);
	}
	cout << ret << '\n';
	return 0;
}
