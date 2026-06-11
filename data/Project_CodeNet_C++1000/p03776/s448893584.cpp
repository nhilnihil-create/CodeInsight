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

ll C[51][51];

ll COM(int n, int k) {
	if(k < 0 || k > n) return 0;
	if(k == 0 || k == n) return 1;
	if(C[n][k] != -1) 
		return C[n][k];
	return C[n][k] = COM(n-1,k-1) + COM(n-1,k);
}

void precal() {
	rep(i,0,51) rep(j,0,51) C[i][j] = -1;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	precal();
	int n, a, b;
	cin >> n >> a >> b;
	vl v(n);
	rep(i,0,n) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	if(v[0] == v[a-1]) {
		int c = a;
		rep(i,a,n) {
			if(v[0] == v[i]) {
				c = i+1;
			} else {
				break;
			}
		}
		int m = min(c,b)+1;
		ll cnt = 0;
		rep(i,a,m) {
			cnt += COM(c,i);
		}
		cout << fixed << setprecision(6) << (double)v[0] << '\n';
		cout << cnt << '\n';
	} else {
		int c = 0;
		int k = 0;
		rep(i,0,n) {
			if(v[i] == v[a-1]) {
				c++;
				if(i<=a-1) {
					k++;
				}
			}
		}
		ll ret = 0;
		rep(i,0,a) {
			ret += v[i];
		}
		ll cnt = COM(c,k);
		cout << fixed << setprecision(6) << (double)ret/a << '\n';
		cout << cnt << '\n';
	}
	return 0;
}
