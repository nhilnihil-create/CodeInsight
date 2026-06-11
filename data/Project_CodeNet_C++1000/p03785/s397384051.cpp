#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
 
const int N = 1e5 + 123;
int n, c, k, t[N];
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> c >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	sort(t + 1, t + n + 1);
	int ans = 1, last = t[1], cur = 1;
	for (int i = 2; i <= n; i++) {
		if (t[i] - last > k || cur == c) {
			ans++;
			last = t[i];
			//cout << "last " << t[i] << '\n';
			cur = 1;
		}	else {
			cur++;
		}
	}
	cout << ans;
}
