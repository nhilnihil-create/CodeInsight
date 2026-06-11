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

//解説をみましたところ、根付き木でできるとのことなので書き直します。

pair<int, int> E[200000];
int he[100001], A[100001];
int OK = 1;
int dfs(int p, int mae) {
	ll goukei = 0;
	int saidai = -1;
	for (int q = he[p]; q; q = E[q].second) {
		int to = E[q].first;
		if (to != mae) {
			int tmp = dfs(to, p);
			goukei += tmp;
			chmax(saidai, tmp);
		}
	}
	if (saidai == -1) return A[p];
	ll kari = A[p] * 2 - goukei;
	chmax(saidai, int(kari));
	if (kari < 0 || saidai > A[p]) OK = 0;
	return kari;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	rep1(i, N) A[i] = getint();
	int k = 1;
	rep(i, N - 1) {
		int a = getint(), b = getint();
		E[k] = mp(b, he[a]);
		he[a] = k++;
		E[k] = mp(a, he[b]);
		he[b] = k++;
	}
	if (E[he[1]].second) {
		if (dfs(1, 0)) OK = 0;
	}
	else {
		if (dfs(1, 0) != A[1]) OK = 0;
	}
	if (OK) printf("YES");
	else printf("NO");

	Would you please return 0;
}