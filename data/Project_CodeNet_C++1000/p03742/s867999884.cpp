#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
int main() {
	ll X, Y;
	cin >> X >> Y;
	if (abs(X - Y) <= 1) cout << "Brown" << endl;
	else cout << "Alice" << endl;
}