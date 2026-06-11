#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

//昼間考えてしまって仕事どころではない

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int H, W, h, w;
	cin >> H >> W >> h >> w;

	if (H % h != 0) {
		co("Yes");
		int k = H / h;
		int amari = H % h;
		rep(i, W - 1) cosp(k + 1);
		co(k + 1);
		rep(j, k - 1) {
			rep(i, h - 2) {
				rep(j, W - 1) cosp(0);
				co(0);
			}
			rep(i, W - 1) cosp(-k - 2);
			co(-k - 2);
			rep(i, W - 1) cosp(k + 1);
			co(k + 1);
		}
		rep(i, h - 2) {
			rep(j, W - 1) cosp(0);
			co(0);
		}
		rep(i, W - 1) cosp(-k - 2);
		co(-k - 2);
		rep(i, amari - 1) {
			rep(j, W - 1) cosp(0);
			co(0);
		}
		rep(i, W - 1) cosp(k + 1);
		co(k + 1);
	}
	else if (W % w != 0) {
		co("Yes");
		int k = W / w;
		int amari = W % w;
		rep(i, H) {
			cosp(k + 1);
			rep(j, k - 1) {
				rep(j, w - 2) cosp(0);
				cosp(-k - 2);
				cosp(k + 1);
			}
			rep(j, w - 2) cosp(0);
			cosp(-k - 2);
			rep(i, amari - 1) cosp(0);
			co(k + 1);
		}
	}
	else {
		co("No");
	}

	Would you please return 0;
}