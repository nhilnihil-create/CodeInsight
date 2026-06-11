#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	cout << fixed << setprecision(0) << k * pow(k - 1, n - 1) << endl;
	return 0;
}
