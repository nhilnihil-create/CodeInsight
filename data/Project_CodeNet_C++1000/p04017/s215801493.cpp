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

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	int pn = 1;
	if (ci - cn + 16 > cm) {
		if ((ct = getcha()) == '-') { pn = -1; ct = getcha(); }
		A = ct - '0';
		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';;
		return pn * A;
	}
	else {
		if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }
		A = ct - '0';
		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';;
		return pn * A;
	}
}

const int dm = 1 << 20;
char dn[dm], * di = dn;
inline void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint();
	int sa[100001];
	int mae = 0;
	rep1(i, N) {
		int tugi = getint();
		sa[i] = tugi - mae;
		mae = tugi;
	}
	int L = getint(), Q = getint();

	int LA[100001][17];
	rep(i, 17) LA[0][i] = 0;

	int j = 0;
	int d = 0;
	rep1(i, N) {
		d += sa[i];
		while (d > L) {
			j++;
			d -= sa[j];
		}
		LA[i][0] = j;
		int k = j;
		rep1(p, 16) {
			LA[i][p] = LA[k][p - 1];
			k = LA[i][p];
		}
	}

	rep(i, Q) {
		int a = getint(), b = getint();
		if (a > b) swap(a, b);

		int kotae = 0;
		for (int k = 16; k >= 0; k--) {
			if (LA[b][k] >= a) {
				kotae += 1 << k;
				b = LA[b][k];
			}
		}
		putint(kotae + (a != b));
	}

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}