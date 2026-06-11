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
	int n;
	cin >> n;
	vl a(n);
	rep(i,0,n) {
		cin >> a[i];
	}
	ll k = 2;
	ll ret = a[0] - 1;
	rep(i,1,n) {
		if(k == a[i]) {
			k++;
		} else if(k < a[i]) {
			if(a[i]%k) {
				ret += a[i]/k;
			} else {
				ret += (a[i]/k)-1;
			}
		}
	}
	cout << ret << '\n';
	return 0;
}
