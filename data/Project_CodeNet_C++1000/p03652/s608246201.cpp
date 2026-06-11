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
	int n, m;
	cin >> n >> m;
	vector<vi> a(n, vi(m));
	rep(i,0,n) rep(j,0,m) {
		cin >> a[i][j];
		a[i][j]--;
	}

	int ret = n;
	vector<bool> v(m, true);
	rep(iter,0,m) {
		vi cnt(m);
		rep(i,0,n) {
			rep(j,0,m) {
				if(!v[a[i][j]]) continue;
				cnt[a[i][j]]++;
				break;
			}
		}
		int g = 0;
		rep(i,0,m) {
			if(cnt[i] > cnt[g]) {
				g = i;
			}
		}
		ret = min(ret, cnt[g]);
		v[g] = false;
	}
	cout << ret << endl;
	return 0;
}
