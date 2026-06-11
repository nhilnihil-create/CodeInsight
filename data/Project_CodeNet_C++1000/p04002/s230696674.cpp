#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;

using namespace std;


int main() {
	ll h, w, n;
	cin >> h >> w >> n;
	set<P> s;
	set<P> t;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		s.insert({ a,b });
		REP(j, 3)REP(k, 3)t.insert({ a - j,b - k });
	}

	VLL j(10, 0);
	for (P p : t) {
		int x = p.first;
		int y = p.second;
		if (0 < x&&x + 2 <= h && 0 < y&&y + 2 <= w) {
			int res = 0;
			REP(j, 3)REP(k, 3)res += s.count({ x + j,y + k });
			j[res]++;
		}
		

	}
	j[0] = (h - 2)*(w - 2) - j[1] - j[2] - j[3] - j[4] - j[5] - j[6] - j[7] - j[8] - j[9];
	REP(i, 10)cout << j[i] << endl;

	return 0;
}