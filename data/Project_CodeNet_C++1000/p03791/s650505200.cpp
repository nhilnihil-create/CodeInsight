#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define boost() ios_base :: sync_with_stdio(0); cin.tie(); cout.tie(); cout << fixed; cout << setprecision(15); srand(time(NULL))
#define endl '\n'
typedef long long ll;
const int _N = 1e5 + 11;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, pos[_N], bair[_N], cnt[_N], res = 1;

int main() {
	boost();
	#ifndef ONLINE_JUDGE
//		freopen("in", "r", stdin);
	#endif
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pos[i];
	bair[0] = 1; bair[1] = 1;
	for (int i = 2; i < n; i++) {
		int need = i - bair[i - 1];
		int bga = pos[i - 1] - (i - bair[i - 1] + 1);	
		if (bga >= need) bair[i] = bair[i - 1];
		else bair[i] = bair[i - 1] + 1;
	}
	for (int i = 0; i < n; i++) cnt[bair[i]] += 1;
	for (ll i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
		res = (res * (cnt[i] - (i - 1))) % MOD;
	}
//	for (int i = 0; i < n; i++) cout << bair[i] << " "; cout << endl;
	cout << res << endl;
	return 0;
}
