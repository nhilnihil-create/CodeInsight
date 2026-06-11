# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <cmath>
# include <functional>
# include <utility>
# include <queue>
# include <stack>
# define MOD 1000000007
# define INF 2000000000
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;
using namespace std;
std::vector<bool> IsPrime;

int main() {
	long long  counter = 0, maxi = -1, mini = INF, pass = 0;
	//new
	ll n, m;
	char gridA[50][50], gridB[50][50];
	rep(i, 50) {
		rep(j, 50) {
			gridA[i][j] = ' ';
			gridB[i][j] = ' ';
		}
	}
	cin >> n >> m;
	rep(i, n) {
		rep(j, n) {
			cin >> gridA[i][j];
		}
	}
	rep(i, m) {
		rep(j, m) {
			cin >> gridB[i][j];
		}
	}
	bool ans=false;
	for (ll j = 0; j < n - m + 1; j++) {
		for (ll i = 0; i < n - m + 1; i++) {
			counter = 0;
			rep(x, m) {
				rep(y, m) {
					if (gridA[i + x][j + y] == gridB[x][y]) {
						counter++;
					}
				}
			}
			if (m*m==counter)ans = true;
		}
	}
	if (ans)cout << "Yes" << endl;
	else cout << "No" << endl;
}
