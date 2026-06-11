#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int N, A, B; cin >> N >> A >> B;
	ll T = B - A;
	if (T < 0) {
		cout << "0" << endl;
	} else if (T == 0) {
		cout << "1" << endl;
	} else if (N == 1) {
		cout << "0" << endl;
	} else if (N == 2) {
		cout << "1" << endl;
	} else {
		ull ans = 1 + (N - 2) * T;
		cout << ans << endl;
	}
}
