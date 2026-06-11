#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
	int N, M;
	cin >> N >> M;
	Graph t(N);
	rep(i, M) {
		int a, b;
		cin >> a >> b; a--; b--;
		t.at(a).push_back(b);
		t.at(b).push_back(a);
	}
	rep(i, N) {
		cout << t.at(i).size() << endl;
	}
}