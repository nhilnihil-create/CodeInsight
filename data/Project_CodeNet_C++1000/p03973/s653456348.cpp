#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define mkp(a,b) make_pair(a,b)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<int ,P> PP;
struct edge { int to; int to2; int cost; };
int a[100006];

int divi(int a, int b) {
	if (a%b)return a / b;
	else return (a / b) - 1;
}

signed main() {
	int n; cin >> n;
	int ans = 0;
	rep(i, n)cin >> a[i];
	int mx = 1;
	rep(i, n) {
		ans += divi(a[i], mx);
		if (mx == 1)mx++;
		else {
			if (a[i] == mx)mx++;
		}
	}
	cout << ans << endl;
}