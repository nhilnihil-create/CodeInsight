#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0; i<ll(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 998244353;




int main() {

	int n, m;
	cin >> n >> m;
	map<int, int> a;
	VI same(m + 1, 0);
	VI b(m + 1, 0);


	REP(i, n) {
		int x;
		cin >> x;
		a[x]++;
		if (a[x] % 2 == 0) {
			same[x%m]++;
		}
		b[x%m]++;
	}

	int ans = b[0] / 2;

	for (int i = 1; i * 2 < m; i++) {

		int j = min(b[i], b[m - i]);
		ans += j;

		ans += min((b[i] - j) / 2, same[i]);
		ans += min((b[m - i] - j) / 2, same[m - i]);
	}

	if (m % 2 == 0) {
		ans += b[m / 2] / 2;
	}

	cout << ans << endl;




}

