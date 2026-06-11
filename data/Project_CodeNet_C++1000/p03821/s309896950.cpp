#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n;
	cin >> n;
	vector<int>A(n), B(n);
	rep(i, n)cin >> A[i] >> B[i];
	ll btn = 0;
	for (int i = n - 1; i >= 0; i--) {
		if ((A[i] + btn) % B[i] != 0)btn += ll((B[i] * ceil(double(A[i] + btn) / double(B[i]))) - (A[i]+ btn));
	}
	cout << btn << endl;
	return 0;
}

