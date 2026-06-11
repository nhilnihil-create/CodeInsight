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
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint(), L = getint(), T = getint();
	int X0;
	char W0;
	X0 = getint();
	W0 = *ci++;
	ci++;


	int aite = 0;
	int kaisuu = 0;
	
	int T1 = T % L;
	int T2 = (L - (T % L)) % L;

	vector<int> V, A, B, C, D;
	if (W0 == '1') {
		if (X0 + T1 < L) A.pb(X0 + T1);
		else B.pb(X0 + T1 - L);
	}
	else {
		if (X0 + T2 < L) C.pb(X0 + T2);
		else D.pb(X0 + T2 - L);
	}

	rep(i, N - 1) {
		int x = getint();
		int w = getcha();
		getcha();

		if (w == '1') {
			if (x + T1 < L) A.pb(x + T1);
			else B.pb(x + T1 - L);
		}
		else {
			if (x + T2 < L) C.pb(x + T2);
			else D.pb(x + T2 - L);
		}

		if (w != W0) {
			aite++;
			if (W0 == '1') {
				if (X0 >= x) x += L;
				while (X0 + T1 > x - T1) {
					kaisuu++;
					x += L;
				}
			}
			else {
				if (X0 <= x) x -= L;
				while (X0 - T1 <= x + T1) {
					kaisuu++;
					x -= L;
				}
			}
		}

	}

	kaisuu += (T / L) * 2 * aite;
	T = T % L;
	kaisuu %= N;

	rep(i, A.size()) B.pb(A[i]);
	rep(i, C.size()) D.pb(C[i]);
	
	int p1 = 0, p2 = 0, p0 = 0;
	while (p0 < N) {
		if (p1 == B.size()) { 
			V.pb(D[p2]);
			p2++;
		}
		else if (p2 == D.size()) {
			V.pb(B[p1]);
			p1++;
		}
		else if (B[p1] < D[p2]) {
			V.pb(B[p1]);
			p1++;
		}
		else {
			V.pb(D[p2]);
			p2++;
		}
		p0++;
	}

	if (W0 == '1') {
		int doko = (X0 + T) % L;
		int itr = lower_bound(V.begin(), V.end(), doko) - V.begin();

		int kotae[100100];
		int kari = N + kaisuu - itr;
		for (int i : V) {
			kotae[kari % N] = i;
			kari++;
		}
		rep(i, N) putint(kotae[i]);
	}
	else {
		int doko = (X0 - (T % L) + L) % L;
		int itr = lower_bound(V.begin(), V.end(), doko) - V.begin();

		int kotae[100100];
		int kari = N + N - kaisuu - itr;
		for (int i : V) {
			kotae[kari % N] = i;
			kari++;
		}
		rep(i, N) putint(kotae[i]);
	}
	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}