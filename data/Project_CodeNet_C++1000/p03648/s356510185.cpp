#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		





int main() {
	
	ll k;
	cin >> k;

	VLL v(50);
	if (k < 50) {
		REP(i, 50)v[i] = 49;
	}
	else {
		k -= 50;
		REP(i, 50) {
			v[i] = 50 + k / 50;
		}
	}
	k %= 50;
	REP(i, k) {
		REP(j, 50) {
			if (i == j)v[j] += 50;
			else v[j]--;
		}
	}
	cout << 50 << endl;
	REP(i, 50)cout << v[i] << ' ';
}