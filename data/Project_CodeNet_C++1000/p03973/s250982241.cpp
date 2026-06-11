#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0; i<int(n); i++)
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
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 998244353;



int main() {
	int n;
	cin >> n;

	VI a(n);
	

	REP(i, n) {
		cin >> a[i];
	}

	ll ans = a[0] - 1;
	a[0] = 1;

	
	int di = 1;

	REP(i, n) {
		if (di > a[i])continue;
		if (di == a[i]) {
			di++;
			continue;
		}
		if (a[i] % di == 0) {
			ans += a[i] / di - 1;
		}
		else {
			ans += a[i] / di;
		}
	}
	cout << ans << endl;


}


