#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;


int main() {
	int N, K;
	cin >> N >> K;
	vector<int> X(N);
	int ans = 0;
	rep(i, N) {
		cin >> X.at(i);
		if (X.at(i) > K-X.at(i)) {
			ans += (K-X.at(i)) * 2;
		}
		else {
			ans += X.at(i) * 2;
		}
	}
	cout << ans << endl;
}