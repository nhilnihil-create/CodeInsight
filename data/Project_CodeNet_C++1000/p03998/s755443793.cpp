#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	vector<int> index(3, 0);
	int turn = 0;
	while (true) {
		string t = s[turn];
		int i = index[turn];
		int n = t.size();
		if (i >= n) {
			char c = 'A' + turn;
			cout << c << endl;
			return;
		} else {
			index[turn]++;
			turn = t[i] - 'a';
		}
	}
}

int main() {
	solve();
	return 0;
}