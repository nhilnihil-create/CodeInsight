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
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const int  INF = 1 << 29;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }



int main() {

	ll w, h;
	cin >> w >> h;
	vector<pair<ll, bool>> v;

	REP(i, w) {
		int x;
		cin >> x;
		v.push_back({ x,true });
	}

	REP(i, h) {
		int x;
		cin >> x;
		v.push_back({ x,false });
	}

	sort(ALL(v));

	ll ans = 0;

	int ww = w + 1;
	int hh = h + 1;

	REP(i, w + h) {


		if (v[i].second) {
			ans += v[i].first*hh;
			ww--;

		}
		else {
			ans += v[i].first*ww;
			hh--;
		}
	}
	cout << ans << endl;



}