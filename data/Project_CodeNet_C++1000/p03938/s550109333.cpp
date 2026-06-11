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
const int MOD = 998244353;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int n;
	cin >> n;
	vi p(n);
	vi idx(n+1);
	rep(i,0,n) {
		cin >> p[i];
		idx[p[i]] = i;
	}
	// c[i] = a[i+1] - a[i];
	// d[i] = b[i] - b[i+1];
	vi c(n,1);
	vi d(n,1);
	rep(i,1,n) {
		int a = idx[i];
		int b = idx[i+1];
		if(a<b) {
			c[i] += b-a;
		} else {
			d[i] += a-b;
		}
	}

	vi a(n+1);
	a[1] = 1;
	rep(i,2,n+1) {
		a[i] = c[i-1] + a[i-1];
	}
	vi b(n+1);
	b[n] = 1;
	per(i,1,n) {
		b[i] = b[i+1] + d[i];
	}
	rep(i,1,n+1) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	rep(i,1,n+1) {
		cout << b[i] << ' ';
	}
	return 0;
}
