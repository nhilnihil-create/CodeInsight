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

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), M = getint();

	ll B[100001] = {};
	int mae = getint();
	int a1 = mae;
	int nanshuu = 0;
	ll kihon = 0;
	rep1(i, N - 1) {
		int a = getint();
		int sa = a - mae;
		if (sa < 0) {
			sa += M;
			nanshuu++;
			kihon -= M - mae;
		}
		B[a] += sa;
		mae = a;
	}
	int aN = mae;
	kihon += (ll)nanshuu * M + aN - a1;

	ll saishou = kihon;
	rep1(x, M - 1) {
		kihon += B[x] - nanshuu - (x > a1) + (x > aN);
		if (saishou > kihon) saishou = kihon;
	}

	printf("%lld\n", saishou);

	Would you please return 0;
}