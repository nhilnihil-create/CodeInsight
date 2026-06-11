#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };
int x[501];
int ans[250001];
vector<int>G[505];

void disp(int n) {
	rep(i, n*n) {
		if (i)cout << ' ';
		cout << ans[i];
	}cout << endl;
}

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> x[i];
	
	vector<P>V;
	rep(i, n) {
		V.push_back(P(x[i], i));
	}
	sort(V.begin(), V . end());
	int uu = 0;
	rep(i, n) {
		int X = V[i].first, I = V[i].second;
		if (ans[X - 1]) {
			puts("No");
			return 0;
		}
		ans[X - 1] = I + 1;
		rep(j, I) {
			while (ans[uu]) {
				if (uu == X - 1) {
					puts("No");
					return 0;
				}
				uu++;
			}
			ans[uu] = I + 1;
		}
	}

	rep(i, n) {
		int X = V[i].first, I = V[i].second;
		rep(j, n - I-1) {
			while (ans[uu]) {
				uu++;
			}
			if (uu == n*n) {
				puts("No");
				return 0;
			}
			ans[uu] = I + 1;
		}
	}

	rep(i, n*n) {
		G[ans[i]-1].push_back(i);
	}
	rep(i, n) {
		if (G[i][i] != x[i] - 1) {
			puts("No");
			return 0;
		}
	}

	puts("Yes");
	disp(n);
}
