#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
const int INF = 1000000000;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T & a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T & a, T b) { if (a > b) { a = b; return 1; } return 0; }

GraphC A(100, vector<char>(100));

int main() {
	int H, W;
	cin >> H >> W;
	rep(i, H) {
		rep(j, W) {
			cin >> A.at(i).at(j);
		}
	}
	rep(i, H) {
		rep(j, W) {
			cout << A.at(i).at(j);
		}
		cout << endl;
		rep(j, W) {
			cout << A.at(i).at(j);
		}
		cout << endl;
	}
}