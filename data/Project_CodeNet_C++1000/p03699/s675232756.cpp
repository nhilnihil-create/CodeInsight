#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int main() {
	int N; cin >> N;
	vector<int> v(N);
	int sum = 0;
	rep(i, N) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum % 10 != 0) {
		cout << sum << endl;
		return 0;
	}
	int mi = INF;
	rep(i, N) {
		if (v[i] % 10 == 0) continue;
		mi = min(mi, v[i]);
	}
	if (mi == INF) {
		cout << "0" << endl;
	} else {
		cout << sum - mi << endl;
	}
}