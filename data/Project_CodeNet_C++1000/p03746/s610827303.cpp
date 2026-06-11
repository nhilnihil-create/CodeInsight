#include<cstdio>
#include<vector>
//#include<bits/stdc++.h>
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
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint(), M = getint();

	int E[200010], ne[200010], H[100010] = {};
	int k = 1;
	rep(i, M) {
		int a = getint(), b = getint();
		E[k] = b;
		ne[k] = H[a];
		H[a] = k++;
		E[k] = a;
		ne[k] = H[b];
		H[b] = k++;
	}

	bool S[100010] = {};
	S[1] = 1; 
	S[E[H[1]]] = 1;
	vector<int> kotae1, kotae2;
	kotae1.pb(1);
	kotae2.pb(E[H[1]]);

	int ima = 1;
	while (true) {
		int nakatta = 1;
		for (int i = H[ima]; i; i = ne[i]) {
			int to = E[i];
			if (!S[to]) {
				kotae1.pb(to);
				ima = to;
				S[to] = 1;
				nakatta = 0;
				break;
			}
		}
		if (nakatta) break;
	}
	ima = E[H[1]];
	while (true) {
		int nakatta = 1;
		for (int i = H[ima]; i; i = ne[i]) {
			int to = E[i];
			if (!S[to]) {
				kotae2.pb(to);
				ima = to;
				S[to] = 1;
				nakatta = 0;
				break;
			}
		}
		if (nakatta) break;
	}

	printf("%d\n", kotae1.size() + kotae2.size());
	rep(i, kotae1.size()) {
		printf("%d ", kotae1[kotae1.size() - i - 1]);
	}
	rep(i, kotae2.size()) {
		printf("%d ", kotae2[i]);
	}

	Would you please return 0;
}