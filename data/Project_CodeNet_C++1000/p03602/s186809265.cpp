#include <iostream>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

const int MOD = (int) 1e9 + 7;

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	ll A[n][n];
	REP(i, n) {
		REP(j, n) {
			cin >> A[i][j];
		}
	}
	
	bool exist = true;
	bool f[n][n];
	REP(i, n) {
		REP(j, n) {
			f[i][j] = false;
		}
	}
	REP(k, n) {
		REP(i, n) {
			REP(j, n) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					cout << "-1" << endl;
					return 0;
				}
				if (A[i][j] == A[i][k] + A[k][j] && k != i && k != j) {
					f[i][j] = true;
				}
			}
		}
	}
	
	ll sum = 0;
	REP(i, n) {
		REP(j, n) {
			if (!f[i][j]) {
				sum += A[i][j];
			}
		}
	}
	
	cout << sum / 2 << endl;
	return 0;
}