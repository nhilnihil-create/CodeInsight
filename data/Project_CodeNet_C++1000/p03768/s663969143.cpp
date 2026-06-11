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
char cn[cm], * ci = cn + cm, ct;

template<typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}
template <typename T> inline void Out(T x) {if(x > 9) Out(x / 10); putchar(x % 10 + '0');}
template <typename T> inline void Cout(T x, char c) {if(x < 0) putchar('-'); x = abs(x); Out(x); putchar(c);}
template <typename T, typename... Args> inline void Cin(T& a, Args&... args) {Cin(a);Cin(args...);}
template <typename T, typename... Args> inline void Cout(T a, char c, Args... args) {Cout(a, c);Cout(args...);}

const int dm = 1 << 20;
char dn[dm], * di = dn;
inline void putint(int X) {
	if (X == 0) {
		*di++ = '0';
		*di++ = '\n';
		return;
	}
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}


pair<int, int> E[200001];
int H[200001];
int kotae[100001];
int Vis[100001];
void sagasu(int P, int D, int C) {
	if (D == 0 && kotae[P] == 0) kotae[P] = C;
	else if (Vis[P] < D) {
		Vis[P] = D;
		if (kotae[P] == 0) kotae[P] = C;
		for (int p = H[P]; p; p = E[p].second) {
			sagasu(E[p].first, D - 1, C);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M, Q;
	Cin(N, M);
	for (int i = 1; i < 2 * M; i += 2) {
		int a, b; Cin(a, b);
		E[i] = mp(a, H[b]);
		H[b] = i;
		E[i + 1] = mp(b, H[a]);
		H[a] = i + 1;
	}
	Cin(Q);
	int v[100000], d[100000], c[100000];
	rep(i, Q) {
		Cin(v[i], d[i], c[i]);
	}
	for (int i = Q - 1; i >= 0; i--) {
		sagasu(v[i], d[i], c[i]);
	}
	rep1(i, N) {
		Cout(kotae[i], '\n');
	}

	Would you please return 0;
}
