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

int N, K;
int D[2001];
int E[4001], ne[4001], he[2001];
void dfs(int v, int d) {
	D[v] = d;
	for (int to = he[v]; to; to = ne[to]) {
		if (D[E[to]] < 0) dfs(E[to], d + 1);
	}
}
int d, k;
int dfs2(int v, int prev) {
	int ret = 1;
	d++;
	for (int to = he[v]; to; to = ne[to]) {
		if (E[to] != prev && d <= k) ret += dfs2(E[to], v);
	}
	d--;
	return ret;
}

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread(cn, 1, cm, stdin); ci = cn; }
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


	N = getint();
	K = getint();
	k = K / 2;
	int tmp = 1;
	int jisuu[2001] = {};
	rep(i, N - 1) {
		int a = getint(), b = getint();
		E[tmp] = b;
		ne[tmp] = he[a];
		he[a] = tmp++;
		E[tmp] = a;
		ne[tmp] = he[b];
		he[b] = tmp++;
		jisuu[a]++;
		jisuu[b]++;
	}

	if (K == 1) {
		printf("%d\n", N - 2);
		return 0;
	}

	rep1(j, N) D[j] = -1;
	dfs(1, 0);
	int saidai = 0;
	int doko, doko2;
	rep1(i, N) if (saidai < D[i]) {
		saidai = D[i];
		doko = i;
	}
	rep1(j, N) D[j] = -1;
	dfs(doko, 0);
	saidai = 0;
	bool muri[2001] = {};
	rep1(i, N) {
		if (saidai < D[i]) {
			saidai = D[i];
			doko2 = i;
		}
		if (D[i] < k) {
			muri[i] = 1;
		}
	}
	if (saidai <= K) {
		printf("0\n");
		return 0;
	}
	rep1(j, N) D[j] = -1;
	dfs(doko2, 0);
	rep1(i, N) {
		if (D[i] < k) muri[i] = 1;
		if (jisuu[i] == 1) {
			muri[i] = 1;
			if (K > 3) {
				int j = E[he[i]];
				if (jisuu[j] == 2) muri[j] = 1;
			}
		}
	}

	if (K % 2 == 0) {
		int kotae = N;
		rep1(i, N) {
			if (!muri[i]) {
				int kazu = dfs2(i, -1);
				kotae = min(kotae, N - kazu);
			}
		}
		printf("%d", kotae);
	}
	else {
		int kotae = N;
		rep1(z, N - 1) {
			int i = E[z * 2];
			int j = E[z * 2 - 1];
			if (!muri[i] && !muri[j]) {
				int kazu = dfs2(i, j) + dfs2(j, i);
				kotae = min(kotae, N - kazu);
			}
		}
		printf("%d", kotae);
	}

	Would you please return 0;
}