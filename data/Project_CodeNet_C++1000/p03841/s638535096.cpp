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
	int n;
	cin >> n;
	vi x(n);
	rep(i, n) cin >> x[i], --x[i];
	vi a(n*n, -1);
	rep(i, n) a[x[i]] = i;
	int idx = 0;
	bool f = true;
	vi id(n);
	rep(i, n) id[i] = i;
	sort(all(id), [&](int a, int b) {return x[a] < x[b];});
	rep(i, n) {
		rep(j, id[i]) {
			while(a[idx]!=-1) ++idx;
			a[idx] = id[i];
		}
		if(idx > x[id[i]]) f = false;
	}
	idx = (int)a.size()-1;
	repr(i, n) {
		rep(j, n-1-id[i]) {
			while(a[idx] != -1) --idx;
			a[idx] = id[i];
		}
		if(idx < x[id[i]]) f = false;
	}
	cout << (f?"Yes" : "No") << endl;
	if(f) {
		rep(i, a.size()) {
			if(i != 0) cout << " ";
			cout << a[i]+1; 
		}
		cout << endl;
	}
	return 0;
}