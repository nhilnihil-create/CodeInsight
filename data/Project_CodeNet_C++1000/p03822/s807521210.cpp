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
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 998244353;


int ans = 0;

VI a[100005];

int dfs(int i) {
	VI v;
	for (int j : a[i]) {
		v.push_back(dfs(j));
	}
	sort(ALL(v));
	reverse(ALL(v));
	int ans = 0;
	REP(j, v.size()) {
		ans = max(ans, j + v[j] + 1);
	}
	return ans;
}

int main() {

	int n;
	cin >> n;
	REP(i, n - 1) {
		int b;
		cin >> b;
		b--;
		a[b].push_back(i + 1);
	}

	cout << dfs(0) << endl;
	

}

