#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std; using ll = long long;
using ull = unsigned long long; using P = pair<int, int>;
const int INF = 1e9; const int MOD = 1000000007;
const int dx[] = {-1,0,1,0}; const int dy[] = {0,-1,0,1};
//const int dx[] = {-1,-1,-1, 0, 0, 1, 1, 1}; const int dy[] = {-1, 0, 1,-1, 1,-1, 0, 1};
#define PI 3.14159265358979323846264338327950L //setprecision(15)

int main() {
	int A, B, C; cin >> A >> B >> C;
	if (A == B && B == C && A % 2 == 0) {
		cout << "-1" << endl; return 0;
	}
	ll ans = 0;
	while (1) {
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			cout << ans << endl; return 0;
		}
		ans++;
		int a = A, b = B, c = C;
		A = b / 2 + c / 2;
		B = a / 2 + c / 2;
		C = a / 2 + b / 2;
	}
	cout << ans << endl;
}