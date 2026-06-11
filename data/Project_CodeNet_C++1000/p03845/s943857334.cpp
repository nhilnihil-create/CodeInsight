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




int main() {
	int N;
	cin >> N;
	vector<int> T(N);
	int tmp = 0;
	rep(i, N) {
		cin >> T.at(i);
		tmp += T.at(i);
	}
	int M;
	cin >> M;
	
	rep(i, M) {
		int num, a,add;
		cin >> num >> a; num--;
		add = a - T.at(num);
		cout << tmp + add << endl;
	}
}