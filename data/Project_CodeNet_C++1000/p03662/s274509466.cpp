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
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;




int v[100010][2];
VI d[100010];
int id;

void dfs(int a, int b = -1) {
	if (b != -1)v[a][id] = v[b][id] + 1;

	for (int i : d[a])if (i != b)dfs(i, a);
}


int main() {
	int n;
	cin >> n;
	REP(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	id = 0;
	dfs(0);
	id = 1;
	dfs(n - 1);

	int res = 0;
	REP(i, n) {
		if (v[i][0] <= v[i][1])res++;
	}
	if (res >= n / 2 + 1)cout << "Fennec" << endl;
	else cout << "Snuke" << endl;

}