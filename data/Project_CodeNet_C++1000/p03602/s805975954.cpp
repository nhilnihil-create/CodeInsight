
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;
typedef pair<ll, ll > P;
const int MOD = 1000000007;


int main() {
	ll i, j, k, l, m, n, sum, flag, cc, M, X, H, W, N,Y,Z,K;
	cc = 0;
	flag = 0;
	cin >> N;
	ll A[305][305];
	REP(i, 0, N) {
		REP(j, 0, N) {
			cin >> A[i][j];
		}
	}
	ll ans = 0;
	bool d[305][305];
	REP(i, 0, N) {
		REP(j, 0, N) {
			d[i][j] = 0;
		}
	}
	REP(i, 0, N) {
		REP(j, 0, N) {
			REP(k, 0, N) {
				if (A[i][j] > A[i][k] + A[k][j]) {
					output("-1");
					return 0;
				}
				if (A[i][j] == A[i][k] + A[k][j] &&A[i][k]>0&&A[k][j]>0) {
					d[i][j] = 1;
				}
			}
		}
	}
	REP(i, 0, N) {
		REP(j, i, N) {
			if (d[i][j] == 0) {
				ans += A[i][j];
			}
		}
	}
	output(ans);
	return 0;
}



