#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

int main() {
	int a, b;
	cin >> a >> b;
	bool ans = false;
	if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0)ans = true;
	if (ans) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}
