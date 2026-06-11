#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
int MOD = 1000000007;
double PI = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define For(i,s,n) for (int i=s;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define All(c) (c).begin(), (c).end()
#define Print(x) cout<<(x)<<"\n"

int N, A;
int X[51];
ll dp[51][51][2501];

int main() {
	cin >> N >> A;
	rep(i, N) cin >> X[i];


	rep(i, 51) {
		rep(j, 51) {
			rep(k, 2501) {
				if (i == 0 && j == 0 && k == 0) {
					dp[i][j][k] = 1;
				}
				else if (i>=1 && k<X[i-1]) {
					dp[i][j][k] = dp[i - 1][j][k];
				}
				else if (i>=1 && j>=1 && k>=X[i-1]){
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - X[i-1]];
				}
			}
		}
	}

	ll ans = 0;
	rep1(i, N+1) {
		ans += dp[N][i][i * A];
	}
	cout << ans << endl;
}