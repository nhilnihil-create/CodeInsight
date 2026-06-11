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

const int cm = 1 << 14;
char cn[cm], * ci = cn, ct;
inline int getint() {
	int A = 0;
	while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	fread_unlocked(cn, 1, cm, stdin);

	int N = getint();
	ll A = 1, B = 1;
	rep(i, N) {
		int a = getint(), b = getint();
		ll k = max((A + a - 1) / a, (B + b - 1) / b);
		A = a * k;
		B = b * k;
	}

	printf("%lld", A + B);

	Would you please return 0;
}