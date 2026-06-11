//#include<bits/stdc++.h>
#include<cstdio>
#include<vector>
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
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

const int dm = 1 << 20;
char dn[dm], * di = dn;
inline void putint(int X) {
	if (X == 0) {
		*di++ = '0';
		*di++ = '\n';
		return;
	}
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
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), L = getint(), T = getint();
	int X;
	char W;
	X = getint();
	W = *ci++;
	ci++;
	int amari = T % L * 2;
	int round = T / L * 2;

	ll kaisuu = 0;
	vector<int> A, B;
	if (W == '1') A.pb(X);
	else B.pb(X);

	rep(i, N - 1) {
		int x = getint();
		char w = getcha();
		getcha();

		if (w == '1') A.pb(x);
		else B.pb(x);

		if (W != w) {
			kaisuu += round;
			int kari;
			if (W == '1') kari = x - X;
			else kari = X - x;
			while (kari <= 0) kari += L;
			kari -= amari;
			while (kari <= 0) {
				kari += L;
				kaisuu++;
			}
		}
	}
	amari /= 2;

	
	int NA = A.size();
	int NB = B.size();
	int AA[100000], BB[100000];
	int k = 0;
	rep(i, NA) {
		if (A[i] + amari >= L) AA[k++] = A[i] + amari - L;
	}
	rep(i, NA) {
		if (A[i] + amari < L) AA[k++] = A[i] + amari;
	}
	k = 0;
	rep(i, NB) {
		if (B[i] - amari >= 0) BB[k++] = B[i] - amari;
	}
	rep(i, NB) {
		if (B[i] - amari < 0) BB[k++] = B[i] - amari + L;
	}

	int zenbu[100000];
	int k1 = 0, k2 = 0;
	rep(i, N) {
		if (k1 == NA) zenbu[i] = BB[k2++];
		else if (k2 == NB) zenbu[i] = AA[k1++];
		else if (AA[k1] <= BB[k2]) zenbu[i] = AA[k1++];
		else zenbu[i] = BB[k2++];
	}

	int doko;
	if (W == '1') {
		int itiban = (X + T) % L;
		for (int i = N - 1; i >= 0; i--) {
			if (zenbu[i] == itiban) {
				doko = i;
				break;
			}
		}
	}
	else {
		int itiban = ((X - T) % L + L) % L;
		rep(i, N) {
			if (zenbu[i] == itiban) {
				doko = i;
				break;
			}
		}
	}

	int kotae[100000];

	if (W == '1') kaisuu %= N;
	else kaisuu = ((-kaisuu) % N + N) % N;
	for (int i = doko; i < N; i++) {
		kotae[kaisuu++] = zenbu[i];
		kaisuu %= N;
	}
	rep(i, doko) {
		kotae[kaisuu++] = zenbu[i];
		kaisuu %= N;
	}
	rep(i, N) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}