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
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}
const int dm = 1 << 20;
char dn[dm], * di = dn;
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
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}
void pakuri_sort(int N, int A[]) {
	const int b = 8;
	int tmp[100001];
	rep(k, 4) {
		int kazu[1 << b] = {}, kazu2[1 << b] = {};
		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];
		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];
		k++;
		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];
		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];
	}
}
int A[100001];
int MA[100001], MI[100001];
int saidai, k = 1, k2 = 1;
ll kotae[100001];

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	rep(i, N) {
		int a = getint();
		if (a > saidai) {
			MA[k] = a;
			MI[k++] = i;
			saidai = a;
		}
		else A[k2++] = a;
	}
	k2--;
	pakuri_sort(k2, A + 1);

	ll cnt = 0;
	for (int i = k - 1; i >= 1; i--) {
		ll tmp = (MA[i] - MA[i - 1]) * ++cnt;
		while (MA[i - 1] < A[k2]) {
			tmp += A[k2] - MA[i - 1];
			cnt++;
			k2--;
		}
		kotae[MI[i]] = tmp;
	}

	rep(i, N) putint(kotae[i]);

	fwrite_unlocked(dn, di - dn, 1, stdout);

	Would you please return 0;
}