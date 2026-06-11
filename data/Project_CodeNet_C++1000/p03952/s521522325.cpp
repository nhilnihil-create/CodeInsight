//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, x, ans[N];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	n = 2 * n - 1;
	if (x == n || x == 1) return cout << "No\n", 0;
	cout << "Yes\n";
	if (x == 2){
		ans[n / 2 + 1] = 2;
		ans[n / 2] = 3;
		ans[n / 2 + 2] = 1;
		int pnt = 4;
		for (int i = 1; i <= n; i++){
			if (i == (n / 2 + 1) || i == (n / 2) || i == (n / 2 + 2)) continue;
			ans[i] = pnt++;
		}
		for (int i = 1; i <=n; i++) cout << ans[i] << '\n';
		return 0;
	}
	ans[n / 2 + 1] = x;
	ans[n / 2] = 1;
	ans[n / 2 + 2] = n;
	ans[n / 2 + 3] = 2;
	int pnt = 3;
	for (int i = 1; i <= n; i++){
		if (i == (n / 2 + 1) || i == (n / 2) || i == (n / 2 + 2) || i == (n / 2 + 3)) continue;
		if(pnt == x) pnt++;
		ans[i] = pnt++;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';






	return 0;
}
