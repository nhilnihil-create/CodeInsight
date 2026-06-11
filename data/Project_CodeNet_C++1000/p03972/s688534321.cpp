#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll w, h;
	cin >> w >> h;
	priority_queue<int,vi,greater<int>> a, b;
	REP(i, w) {
		int c;
		cin >> c;	
		a.push(c);
	}
	REP(i, h) {
		int c;
		cin >> c;
		b.push(c);
	}

	ll ans = 0, cnt = 0;
	int cntw = 0, cnth = 0;
	while (cnt < (w+1)*(h+1) - 1) {
		if (!a.empty()&&!b.empty()) {

			if (a.top() <= b.top()) {
				ans += a.top()*(h + 1 - cnth);
				cnt += h + 1 - cnth;
				cntw++;
				a.pop();
			}
			else {
				ans += b.top()*(w + 1 - cntw);
				cnt += w + 1 - cntw;
				cnth++;
				b.pop();
			}
		}
		else if (!a.empty()) {
			ans += a.top()*(h + 1 - cnth);
			cnt += h + 1 - cnth;
			cntw++;
			a.pop();
		}
		else {
			ans += b.top()*(w + 1 - cntw);
			cnt += w + 1 - cntw;
			cnth++;
			b.pop();
		}
	}
	cout << ans << endl;
}
