#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void No() { cout << "No" << endl; }
	void Yes() { cout << "Yes" << endl; }
	void Solve() {
		UL H, W, h, w; cin >> H >> W >> h >> w;
		if (H % h == 0 && W % w == 0) { No(); return; }
		Yes();
		if (H % h) {
			int t = H * 2;
			rep(y, H) {
				rep(x, W) {
					if (x != 0) cout << " ";
					if (y % h == 0) cout << ((h - 1) * t - 1);
					else cout << -t;
				}
				cout << endl;
			}
		}
		else {
			int t = W * 2;
			rep(y, H) {
				rep(x, W) {
					if (x != 0) cout << " ";
					if (x % w == 0) cout << ((w - 1) * t - 1);
					else cout << -t;
				}
				cout << endl;
			}
		}
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}