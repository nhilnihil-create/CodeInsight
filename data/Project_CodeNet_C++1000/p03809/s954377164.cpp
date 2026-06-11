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

pair<int, int> to[200000];
int he[100001], jisuu[100001], A[100001], saidai[100001];
ll goukei[100001];

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	rep1(i, N) A[i] = getint();
	int k = 1;
	rep(i, N - 1) {
		int a = getint(), b = getint();
		jisuu[a]++;
		jisuu[b]++;
		to[k] = mp(b, he[a]);
		he[a] = k++;
		to[k] = mp(a, he[b]);
		he[b] = k++;
	}

	if (N == 2) {
		if (A[1] == A[2]) printf("YES");
		else printf("NO");
		return 0;
	}

	int q[100000], x = 0;
	rep1(i, N) if (jisuu[i] == 1) jisuu[i] = 0;
	int n = N;
	rep1(i, N) if (jisuu[i] == 0) {
		int p = to[he[i]].first;
		goukei[p] += A[i];
		if (saidai[p] < A[i]) saidai[p] = A[i];
		jisuu[p]--;
		if (jisuu[p] == 1) q[x++] = p;
		n--;
	}

	bool OK = 1;
	for (int y = 0; y < n - 1; y++) {
		int i = q[y];
		for (int j = he[i]; j; j = to[j].second) {
			int p = to[j].first;
			if (jisuu[p]) {
				jisuu[p]--;
				if (jisuu[p] == 1) q[x++] = p;

				ll tmp = A[i] * 2 - goukei[i];
				if (saidai[i] < tmp) saidai[i] = tmp;
				goukei[p] += tmp;
				if (saidai[p] < tmp) saidai[p] = tmp;
				if (tmp < 0 || saidai[i] > A[i]) OK = 0;
			}
		}
		jisuu[i] = 0;
	}

	int i = q[n - 1];
	if (saidai[i] > A[i] || goukei[i] != A[i] * 2) OK = 0;

	if (OK) printf("YES");
	else printf("NO");

	Would you please return 0;
}