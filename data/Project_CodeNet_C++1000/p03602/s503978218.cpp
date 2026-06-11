#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;
int n;
ll sum;
void wf(vector<vector<ll>> &b) {
	rep(k,n) rep(i,n) rep(j,n) b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
	return;
}

bool diff(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	rep(i,n) rep(j,n) if (a[i][j]!=b[i][j]) return true;
	return false;
}

void calc(vector<vector<ll>> &b, vector<vector<bool>> &fl) {
	rep(k,n) {
		rep(i,n) {
			rep(j,n) {
				if (i==j||k==i||j==k) continue;
				if (b[i][j]==b[i][k]+b[k][j]) fl[i][j]=false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	cin>>n;
	vector<vector<ll>> a(n, vector<ll>(n));
	sum=0ll;
	rep(i,n) rep(j,n) cin>>a[i][j];
	vector<vector<ll>> b(a);
	vector<vector<bool>> fl(n, vector<bool>(n, true));
	wf(b);
	if (diff(a,b)) {
		cout << -1 << endl;
		return 0;
	}
	calc(b,fl);

	rep(i,n) rep(j,n) if (fl[i][j]) sum+=b[i][j];
	cout << sum/2 << endl;
	return 0;
}