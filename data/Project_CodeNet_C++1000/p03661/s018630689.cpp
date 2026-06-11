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
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
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

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	int A[200000];
	ll goukei = 0;
	rep(i, N) {
		A[i] = getint();
		goukei += A[i];
	}

	ll saishou = 1e18;
	ll kari = 0;
	rep(i, N - 1) {
		kari += A[i];
		saishou = min(saishou, abs(kari + kari - goukei));
	}
	printf("%d", saishou);


	Would you please return 0;
}