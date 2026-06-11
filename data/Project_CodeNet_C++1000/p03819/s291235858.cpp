#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
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

const int bm = 100002;
int BIT[bm];
void addp(int A) {
	while (A <= bm) {
		BIT[A]++;
		A += A & -A;
	}
}
void addn(int A) {
	while (A <= bm) {
		BIT[A]--;
		A += A & -A;
	}
}
int query(int A) {
	int ret = 0;
	while (A > 0) {
		ret += BIT[A];
		A -= A & -A;
	}
	return ret;
}

const int cm = 1 << 17;
char cn[cm], *ci = cn + cm, ct;
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
char dn[dm], *di = dn;
inline void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--) *di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), M = getint();
	int L[300001], ne[300001], he[100001] = {};
	rep1(i, N) {
		L[i] = getint();
		int lr = getint();
		lr += 1 - L[i];
		ne[i] = he[lr];
		he[lr] = i;
	}

	int k = N;
	putint(N);
	int cnt2 = 0;
	for (int j = he[1]; j; j = ne[j]) {
		addp(L[j]);
		addn(L[j] + 1);
		cnt2 += L[j] & 1;
		k--;
	}
	if (M >= 2) {
		putint(N - cnt2);
		for (int j = he[2]; j; j = ne[j]) {
			addp(L[j]);
			addn(L[j] + 2);
			k--;
		}
	}
	for (int i = 3; i <= M; i++) {
		int ans = k;
		for (int j = i; j <= M; j += i) {
			ans += query(j);
		}
		if (ans) putint(ans);
		else {
			*di++ = '0';
			*di++ = '\n';
		}
		for (int j = he[i]; j; j = ne[j]) {
			addp(L[j]);
			addn(L[j] + i);
			k--;
		}
	}

	fwrite(dn, 1, di - dn, stdout);

	Would you please return 0;
}