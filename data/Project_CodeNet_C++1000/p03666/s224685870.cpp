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

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	ll p = (b-a-(n-1)*d)/(-c-d);
	//cout << p << endl;
	ll q = (b-a-(n-1)*c)/(-c-d);
	if((b-a-(n-1)*c)%(-c-d) != 0) q++;
	//cout << q << endl;
	if(p < 0 || q >= n) {
		cout << "NO" << endl;
		return 0;
	}
	if(q <= p) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
