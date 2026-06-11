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
	int n, m,k;
	cin >> n >> m >> k;
	int paint = 0;
	REP(i, n){
		paint = i * m;
		REP(j, m+1) {
			if (paint == k) {
				cout << "Yes" << endl;
				return 0;
			}
			paint += n - (i * 2);
		}
	}
	cout << "No" << endl;
	return 0;
}

