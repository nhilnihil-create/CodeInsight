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

int N;
vector<int> a(100005);
vector<bool> b(100005);

int cnt = 0;

int solve(int x) {

	b.at(1) = true;
	
	if (x == 2) {
		cnt++;
		return cnt;
	}

	if (!(b.at(x))) {
		b.at(x) = true;
		cnt++;
		return solve(a.at(x));
	}
	else {
		return -1;
	}
}


int main() {
	cin >> N;
	for (int i = 1; i <= N ; i++)
	{
		cin >> a.at(i);
		b.at(i) = false;
	}
	cout << solve(a.at(1)) << endl;
}