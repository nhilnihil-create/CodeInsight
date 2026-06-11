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
char dn[dm], *di = dn, dt;
inline void putint(ll X) {
	if (!X) {
		*di++ = '0';
		*di++ = '\n';
		return;
	}
	int keta = 0;
	char C[20];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--) *di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint();
	int A[100000];
	rep(i, N) *(A + i) = getint();

	int k = 0, k2 = 1;
	vector<int> V, V2;
	V.pb(0);
	int mae = 0;
	ll B[100001] = {};
	int C[100001] = {};
	rep(i, N) {
		if (A[i] > k) {
			V.pb(A[i]);
			V2.pb(i);
			B[k2] += A[i] - k;
			C[k2]++;
			k = A[i];
			k2++;
			A[i] = 0;
		}
	}
	rep(i, N) if(A[i]) {
		int k3 = lower_bound(V.begin(), V.end(), A[i]) - V.begin();
		B[k3] += A[i] - V[k3 - 1];
		C[k3]++;
	}

	mae = V.back();
	ll l = C[(int)V.size()];
	ll kotae[100001] = {};
	for (int k = (int)V.size() - 2; k >= 0; k--) {
		kotae[V2[k]] = B[k + 1] + l * (mae - V[k]);
		mae = V[k];
		l += C[k + 1];
	}

	rep(i, N) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}