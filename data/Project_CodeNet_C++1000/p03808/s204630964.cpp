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

ll n;
vl a;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	a.resize(n);
	rep(i,0,n) {
		cin >> a[i];
	}

	ll A = 0;
	rep(i,0,n) {
		A += a[i];
	}
	if((A*2) % (n*n + n)) {
		cout << "NO" << '\n';
		return 0;
	} 

	ll B = (A*2) / (n*n + n);
	vl b;
	b.resize(n);
	rep(i,0,n) {
		ll x = B - a[(i+1)%n] + a[i];
		ll y = x % n;
		if((x < 0) || (x % n)) {
			cout << "NO" << '\n';
			return 0;
		}
		b[i] = x / n;
	}
	ll bsum = 0;
	rep(i,0,n) bsum += b[i];
	if(bsum == B) 
		cout << "YES" << '\n';
	else 
		cout << "NO" << '\n';
	return 0;
}
