#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for(int i=(int)(s-1); i>=(int)(e); i--)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

int main(){
	ll N;
	cin >> N;
	vi ans;
	int n;
	repr(i, 50) {
		if(N >= (1LL<<i)-1) {
			n = i;
			break;
		}
	}
	rep(i, n) ans.pb(i);
	N -= (1LL<<n)-1;
	repr(i,n) {
		if(N < (1LL<<i)) continue;
		ans.insert(ans.begin()+i, n++);
		N -= (1LL << i);
	}
	cout << n * 2 << endl;
	rep(i, n) cout << ans[i] + 1 << " ";
	rep(i, n) {
		cout << i+1;
		if(i != n-1) cout << " ";
		else cout << endl;
	}
	return 0;
}