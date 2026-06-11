#include <bits/stdc++.h>

#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pii pair<int, int>
#define mp make_pair
#define f first
#define ll long long
#define ld long double
#define s second
#define vec vector<int>

using namespace std;

const int N = (int) 2e5 + 10;
const int M = (int) 2e6 + 10;
const int K = (int) 20;
const int INF = (int) 1e9 + 7;
const int mod = (int) 998244353;
const ld EPS = (ld) 1e-9;
const ll LINF = (ll) 1e18;

int W, H, w, h;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifdef sony
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	srand(time(0));
	cin >> W >> H >> w >> h;
	for (ll x = 0; x <= 5e7; x++) {
		ll pt = -(w * h - 1) * x - 1; 
		ll negatives = (W / w) * (H / h);
		ll total_sum = (W * H - negatives) * x + negatives * pt;
		if (total_sum > 0) {
			cout << "Yes\n";
			for (int i = 1; i <= W; i++) {
				for (int j = 1; j <= H; j++) {
					if (i % w == 0 && j % h == 0) {
						cout << pt << ' ';
					} else {
						cout << x << ' ';
					}
				}
				cout << endl;
			}
			exit(0);
		}
	}
	cout << "No";
	return 0;	
}