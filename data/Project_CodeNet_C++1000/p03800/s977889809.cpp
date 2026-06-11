#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	for (int k = 0; k < 4; k++) {
		vector<int> sw(n);
		if (k == 0) sw[0] = sw[1] = 0;
		else if (k == 1) {
			sw[0] = 0;
			sw[1] = 1;
		} else if (k == 2) {
			sw[0] = 1;
			sw[1] = 0;
		}
		else sw[0] = sw[1] = 1;

		for (int i = 1; i < n-1; i++) {
			if (sw[i] == 0) {
				if (s[i] == 'o') {
					sw[i+1] = 1 - sw[i-1];
				} else {
					sw[i+1] = sw[i-1];
				}
			} else {
				if (s[i] == 'o') {
					sw[i+1] = sw[i-1];
				} else {
					sw[i+1] = 1 - sw[i-1];
				}
			}
		}
		
		bool b1 = true;
		if (sw[n-1] == 0) {
			if (s[n-1] == 'o') {
				if (sw[n-2] == sw[0]) b1 = false;
			} else {
				if (sw[n-2] != sw[0]) b1 = false;
			}
		} else {
			if (s[n-1] == 'o') {
				if (sw[n-2] != sw[0]) b1 = false;
			} else {
				if (sw[n-2] == sw[0]) b1 = false;
			}
		}
		bool b2 = true;
		if (sw[0] == 0) {
			if (s[0] == 'o') {
				if (sw[n-1] == sw[1]) b1 = false;
			} else {
				if (sw[n-1] != sw[1]) b1 = false;
			}
		} else {
			if (s[0] == 'o') {
				if (sw[n-1] != sw[1]) b1 = false;
			} else {
				if (sw[n-1] == sw[1]) b1 = false;
			}
		}

		if (b1 && b2) {
			string ans = "";
			rep(i,n) ans += (sw[i] ? 'S': 'W');
			cout << ans << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}