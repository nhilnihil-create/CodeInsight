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

int a[N];

bool cmp(int x, int y){
	return (x % 2) < (y % 2);
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		cin >> a[i];
		if (a[i] % 2 == 1) cnt++;
	}
	if (m == 1){
		cout << a[1] << '\n';
		if (n == 1){
			cout << 1 << '\n';
			cout << 1;
			return 0;
		}
		cout << 2 << '\n';
		cout << a[1] - 1 << ' ' << 1 ;
		return 0;
	}
	sort(a + 1, a + m + 1, cmp);
	swap(a[1], a[m - 1]);
	if (cnt > 2) return cout << "Impossible", 0;
	for (int i = 1; i <= m; i++) cout << a[i] << ' ';
	cout << '\n';
	vector<int> ans;
	for (int i = 1; i <= m; i++){
		if (i == 1){
			if (a[i] != 1) ans.pb(a[i] - 1);
		}
		else if (i == m) ans.pb(a[i] + 1);
		else ans.pb(a[i]);
	}
	cout << ans.size() << '\n';
	for (auto u:ans) cout << u << ' ';








	return 0;
}
