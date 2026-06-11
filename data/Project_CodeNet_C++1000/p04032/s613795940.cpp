#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll inf = 1e18 + 7;
const int maxN = 5e4 + 5;

string s;
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> s;
	REP(i, sz(s) - 1) {
		if (s[i] == s[i + 1]) {
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
		}
	}
	REP(i, sz(s) - 2) {
		string tmp = s.substr(i, 3);
		sort(tmp.begin(), tmp.end());
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2]) {
			cout << i + 1 << " " << i + 3 << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << endl;
	return 0;
}
