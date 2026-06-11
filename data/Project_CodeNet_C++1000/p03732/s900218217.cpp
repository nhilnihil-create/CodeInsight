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
	int N, W;
	cin >> N >> W;
	vl w(N);
	vector<vl> v(4);
	ll p;
	rep(i,0,N) {
		int weight, val;
		cin >> weight >> val;
		if(i==0) p = weight;
		v[(weight-p)].pb(val);
	}
	rep(i,0,4) {
		while(v[i].size() != N) {
			v[i].pb(0);
		}
	}
	rep(i,0,4) {
		sort(v[i].rbegin(), v[i].rend());
		v[i].insert(v[i].begin(),1,0);
		rep(j,1,N+1) {
			v[i][j] = v[i][j-1] + v[i][j];
		}
	}
	ll ret = 0;
	rep(a,0,N+1) rep(b,0,N+1) rep(c,0,N+1) rep(d,0,N+1) {
		if(a+b+c+d > N) continue;
		ll curW = p * a + (p+1) * b + (p+2) * c + (p+3) * d;
		if(curW > W) continue;
		ret = max(ret, v[0][a] + v[1][b] + v[2][c] + v[3][d]);
	}
	cout << ret << '\n';
	return 0;
}
