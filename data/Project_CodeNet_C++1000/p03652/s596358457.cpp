#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 998244353;



int a[305][305];

bool b[305];

int ans = INF;

int main() {

	int n, m;
	cin >> n >> m;
	REP(i, n)REP(j, m)cin >> a[i][j];

	REP(i, m) {
		VI v(m + 1, 0);
		int cur = 0;
		int d = 0;
		REP(j, n) {
			REP(k, m) {
				if (!b[a[j][k]]) {
					v[a[j][k]]++;
					break;
				}
			}
		}
		REP(i, m + 1) {
			if (d < v[i]) {
				d = v[i];
				cur = i;
			}
		}
		ans = min(ans, d);
		b[cur] = true;
	}
	cout << ans << endl;


	return 0;
}