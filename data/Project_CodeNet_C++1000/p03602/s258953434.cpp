#define _USE_MATH_DEFINES 
#include <iomanip> 
#include <cmath>  
#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<deque>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl

int N;
ll A[310][310], dp[310][310], ans;
bool dontuse[310][310];

void warshall_floyd() {
	repi(i, 0, N) {
		repi(j, 0, N) {
			repi(k, 0, N) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				if (dp[i][j] == dp[i][k] + dp[k][j] && i!=k && k!=j && j!=i) dontuse[i][j] = true;
			}
		}
	}
}

int main() {
	rd(N);
	repi(i, 0, N) {
		repi(j, 0, N) {
			ll temp;
			rd(temp);
			A[i][j] = dp[i][j] = temp;
		}
	}

	warshall_floyd();

	repi(i, 0, N) {
		repi(j, 0, N) {
			if (A[i][j] != dp[i][j]) {
				wrln(-1);
				return 0;
			}
			if (!dontuse[i][j]) ans += dp[i][j];
		}
	}

	wrln(ans / 2);

	return 0;
}