#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll Q, H, S, D, N;

int main() {
	cin >> Q >> H >> S >> D >> N;
	
	H = min(H, 2 * Q);
	S = min(S, 2 * H);
	if (D > 2 * S) {
		cout << S * N << endl;
	}
	else {
		cout << N / 2 * D + N % 2 * S << endl;
	}
}