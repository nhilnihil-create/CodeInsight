#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
const int inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<P,int>PP;
typedef vector<vector<int>>mat;

int amida[63][100006];

int x[100006];
int a[100006];
int fin[100006];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> x[i];
	int m, k; cin >> m >> k;
	rep(i, m) {
		cin >> a[i]; a[i]--;
	}

	rep(i, n)amida[0][i] = i;
	rep(i,m) {
		swap(amida[0][a[i]], amida[0][a[i] - 1]);
	}
	for (int i = 0; i < 62; i++) {
		rep(j, n) {
			amida[i + 1][j] = amida[i][amida[i][j]];
		}
	}
	rep(i, n)fin[i] = i;
	rep(i, 63) {
		if (k&(1ll << i)) {
			rep(j, n) {
				fin[j] = amida[i][fin[j]];
			}
		}
	}
	int cnt = x[0];
	cout << cnt<<endl;
	rep(i, n - 1) {
		cnt += x[fin[i] + 1] - x[fin[i]];
		cout << cnt << endl;
	}
}