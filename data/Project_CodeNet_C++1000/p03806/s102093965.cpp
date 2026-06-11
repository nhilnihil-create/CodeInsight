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

const int INF = 1e9;
int n, ma, mb;
int a[45];
int b[45];
int c[45];
int dp[45][405][405];
int solve(int pos, int remA, int remB) {
	if(pos == n) {
		bool flag = ((remA * mb) == (remB * ma));
		flag = flag && !(remA%ma);
		flag = flag && !(remB%mb);
		flag = flag && (remA != 0) && (remB != 0);
		if(flag) {
			return 0;
		} else {
			return INF;
		} 
	}

	int& ret = dp[pos][remA][remB];
	if(ret != -1) return ret;
	ret = INF;

	ret = min(ret, solve(pos+1, remA+a[pos], remB+b[pos]) + c[pos]);
	ret = min(ret, solve(pos+1, remA, remB));
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> ma >> mb;
	rep(i,0,n) {
		cin >> a[i] >> b[i] >> c[i];
	}
	memset(dp, -1, sizeof(dp));
	int ret = solve(0,0,0);
	if(ret == INF) {
		cout << -1 << '\n';
	} else {
		cout << ret << '\n';
	}
	return 0;
}
