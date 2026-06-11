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
	vector<P> p(M);
	rep(i, M) {
		cin >> p.at(i).first >> p.at(i).second;
	}

	for (int i = 0; i < M; i++)
	{
		int ans = tmp;
		int m = p.at(i).first; m--;
		ans -= T.at(m);
		int add = p.at(i).second;
		ans += add;

		cout << ans << endl;
	}
	
}