#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
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
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
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
	if (ci - cn + 12 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
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

int to[200001], ne[200001], he[100001];
int kotae[100001];
char d[100001];
const int m = (1 << 20) - 1;
const int m2 = (1 << 30) - m - 1;
void sagasu(int P, int D, int C) {
	if (D == 0 && kotae[P] == 0) kotae[P] = C;
	else if (d[P] < D) {
		d[P] = D;
		if (kotae[P] == 0) kotae[P] = C;
		for (int p = he[P]; p; p = ne[p]) {
			sagasu(to[p], D - 1, C);
		}
	}
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N, M, Q;
	N = getint();
	M = getint();
	int k = 1;
	rep(i, M) {
		int a = getint(), b = getint();
		to[k] = a;
		ne[k] = he[b];
		he[b] = k++;
		to[k] = b;
		ne[k] = he[a];
		he[a] = k++;
	}
	Q = getint();
	int v[100000], d[100000], c[100000];
	rep(i, Q) {
		v[i] = getint();
		d[i] = getint();
		c[i] = getint();
	}
	for (int i = Q - 1; i >= 0; i--) sagasu(v[i], d[i], c[i]);

	rep1(i, N) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}