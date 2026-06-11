#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

/* --------------------------------------- */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	string t = s;
	reverse(ALL(t));
	REP(i,t.size()) {
		if(t[i] == 'b') t[i] = 'd';
		else if(t[i] == 'd') t[i] = 'b';
		else if(t[i] == 'p') t[i] = 'q';
		else if(t[i] == 'q') t[i] = 'p';
	}
	if(s == t) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

/* --------------------------------------- */
