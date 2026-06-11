//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, mn[N][N], a[N], x;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) mn[i][i] = a[i];
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) mn[i][j] = min(mn[i][j - 1], a[j]);
	ll ans = INF;
	for (int i = 0; i <= n; i++){
		ll res = 0;
		for (int j = 0; j < n; j++){
			ll delta = a[j];
			if (i != 0){
				if (j >= i){
					delta = min(delta, mn[j - i][j - 1]);
				}else{
					if (j != 0) delta = min(delta, min(mn[0][j - 1], mn[n - (i - j)][n - 1]));
					else delta = min(delta, mn[n - (i - j)][n - 1]);
				}
			}
			//cout << i << ' ' << delta << '\n';
			res += delta;
		}
		ans = min(ans, res + x * i);
	}
	cout << ans;










	return 0;
}
