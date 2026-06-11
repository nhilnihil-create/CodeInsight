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

//二部グラフかぁ
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

pair<int, int> E[400001];
int H[100001], D[100001];
bool dame[100001];
void dfs(int p, int d, int rt) {
	if (D[p]) {
		if ((d + D[p]) & 1) dame[rt] = true;
		return;
	}
	D[p] = d;
	for (int i = H[p]; i; i = E[i].second) {
		dfs(E[i].first, d + 1, rt);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N = getint(), M = getint();
	rep(i, M) {
		int a = getint(), b = getint();
		E[i + i + 1] = mp(a, H[b]);
		H[b] = i + i + 1;
		E[i + i + 2] = mp(b, H[a]);
		H[a] = i + i + 2;
	}

	ll x = 0, y = 0, z = 0;
	rep1(i, N) {
		if (!D[i]) {
			dfs(i, 1, i);
			if (!H[i]) z++;
			else if (dame[i]) y++;
			else x++;
		}
	}
	co(x* x + (x + y) * (x + y) + 2 * N * z - z * z);

	Would you please return 0;
}