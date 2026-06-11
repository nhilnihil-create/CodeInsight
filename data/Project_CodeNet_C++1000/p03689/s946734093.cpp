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

int pn, nn;
char p[3], n[3];
const int dm = 1 << 21;
char dn[dm], *di = dn;
inline void putps() {
	for (int i = pn - 1; i >= 0; i--) *di++ = *(p + i);
	*di++ = ' ';
}
inline void putp() {
	for (int i = pn - 1; i >= 0; i--) *di++ = *(p + i);
	*di++ = '\n';
}
inline void putns() {
	*di++ = '-';
	for (int i = nn - 1; i >= 0; i--) *di++ = *(n + i);
	*di++ = ' ';
}
inline void putn() {
	*di++ = '-';
	for (int i = nn - 1; i >= 0; i--) *di++ = *(n + i);
	*di++ = '\n';
}
inline void putzs() {
	*di++ = '0';	
	*di++ = ' ';
}
inline void putz() {
	*di++ = '0';
	*di++ = '\n';
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int H, W, h, w;
	cin >> H >> W >> h >> w;

	if (H % h != 0) {
		*di++ = 'Y';
		*di++ = 'e';
		*di++ = 's';
		*di++ = '\n';
		int k = H / h;
		int amari = H % h;
		int X = k + 1;
		while (X) {
			*(p + pn) = '0' + X % 10;
			X /= 10;
			pn++;
		}
		X = k + 2;
		while (X) {
			*(n + nn) = '0' + X % 10;
			X /= 10;
			nn++;
		}

		rep(i, W - 1) putps();
		putp();
		rep(j, k - 1) {
			rep(i, h - 2) {
				rep(j, W - 1) putzs();
				putz();
			}
			rep(i, W - 1) putns();
			putn();
			rep(i, W - 1) putps();
			putp();
		}
		rep(i, h - 2) {
			rep(j, W - 1) putzs();
			putz();
		}
		rep(i, W - 1) putns();
		putn();
		rep(i, amari - 1) {
			rep(j, W - 1) putzs();
			putz();
		}
		rep(i, W - 1) putps();
		putp();
	}
	else if (W % w != 0) {
		*di++ = 'Y';
		*di++ = 'e';
		*di++ = 's';
		*di++ = '\n';
		int k = W / w;
		int amari = W % w;
		int X = k + 1;
		while (X) {
			*(p + pn) = '0' + X % 10;
			X /= 10;
			pn++;
		}
		X = k + 2;
		while (X) {
			*(n + nn) = '0' + X % 10;
			X /= 10;
			nn++;
		}

		rep(i, H) {
			putps();
			rep(j, k - 1) {
				rep(j, w - 2) putzs();
				putns();
				putps();
			}
			rep(j, w - 2) putzs();
			putns();
			rep(i, amari - 1) putzs();
			putp();
		}
	}
	else {
		*di++ = 'N';
		*di++ = 'o';
		*di++ = '\n';
	}

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}