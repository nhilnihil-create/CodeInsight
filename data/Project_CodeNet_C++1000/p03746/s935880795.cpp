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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 998244353;


VI g[100005];
VB b(100005, false);

deque<int> q;

void dfs1(int a) {
	for (int i : g[a]) {
		if (b[i])continue;
		b[i] = true;
		q.push_back(i);
		dfs1(i);
		break;
	}
}

void dfs2(int a) {
	for (int i : g[a]) {
		if (b[i])continue;
		b[i] = true;
		q.push_front(i);
		dfs2(i);
		break;
	}
}

void bfs() {
	q.push_back(0);
	b[0] = true;
	dfs1(0);
	dfs2(0);
}

int main() {

	int n, m;
	cin >> n >> m;

	REP(i, m) {
		int c, d;
		cin >> c >> d;
		c--, d--;
		g[c].push_back(d);
		g[d].push_back(c);
	}

	q.push_back(0);
	b[0] = true;
	dfs1(0);
	dfs2(0);

	cout << q.size() << endl;

	for (int i : q) {
		cout << i + 1 << ' ';
	}



}